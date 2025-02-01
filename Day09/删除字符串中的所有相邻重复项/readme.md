# 删除字符串中的所有相邻重复项

例题：[leetcode 1047 删除字符串中的所有相邻重复项](https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/)

如下图原理，用栈存储字符，最后将栈反转即为答案字符串：

![gif](https://code-thinking.cdn.bcebos.com/gifs/1047.%E5%88%A0%E9%99%A4%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E6%89%80%E6%9C%89%E7%9B%B8%E9%82%BB%E9%87%8D%E5%A4%8D%E9%A1%B9.gif)

```cpp
class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> mirror;
        for (int i = 0; i < s.size(); i++)
        {
            if (mirror.empty() || mirror.top() != s[i])
            {
                mirror.push(s[i]);
            }
            else
            {
                // mirror.top()==s[i]
                mirror.pop();
            }
        }

        // 将栈变成字符串
        string res = "";
        while (!mirror.empty())
        {
            res += mirror.top();
            mirror.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

时间复杂度: O(n)，空间复杂度: O(n)
