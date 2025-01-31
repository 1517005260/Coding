# 翻转字符串里的单词

例题：[leetcode 151 翻转字符串里的单词](https://leetcode.cn/problems/reverse-words-in-a-string/description/)

为了优雅解决，我们将不使用额外的空间做题。所以分三步走：

1. 去除多余空格，仅保留单词间的一个空格

- 这里的思路可以参考[移除数组中的元素](../../Day01/移除元素/)，这里的元素就是空格
- `"the sky is blue "` -> `"the sky is blue"`

2. 反转字符串

- 思路参考昨天的[反转字符串](../../Day07/反转字符串/)
- `"the sky is blue"`-> `"eulb si yks eht"`

3. 单词内部反转

- 调用 2 的函数即可
- `"eulb si yks eht"`-> `"blue is sky the"`

```cpp
class Solution
{
public:
    string reverseWords(string s)
    {
        // 1. 清除多余空格
        removeSpace(s);
        // 2. 反转整个字符串
        reverseString(s, 0, s.size() - 1);
        // 3. 逐个反转单词
        int start = 0;
        for (int i = 0; i <= s.size(); i++)
        {
            // 判断单词结尾：i是空格或已达到字符串结尾
            if (i == s.size() || s[i] == ' ')
            {
                reverseString(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }

    // 去除多余空格
    void removeSpace(string &s)
    {
        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++)
        {
            if (s[fast] != ' ')
            {
                // 不是空格，可以加入slow里
                // 但是这里相比移除元素，还要控制单词间只有一个空格，不能把空格全删完
                if (slow != 0)
                {
                    // 在非第一个单词前面添加空格
                    s[slow++] = ' ';
                }
                while (fast < s.size() && s[fast] != ' ')
                {
                    // 在空格后面添加单词，遇到空格结束
                    s[slow++] = s[fast++];
                }
            }
        }
        // 操作完，需要resize，因为删除了空格，不需要原来这么多空间了
        s.resize(slow);
    }

    // 反转方法
    void reverseString(string &s, int start, int end)
    {
        // 由于这个函数会被s和其子单词调，所以需要传入下标
        for (int i = start, j = end; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }
};
```

时间复杂度: O(n)，空间复杂度: O(1)
