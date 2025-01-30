# 反转字符串 II

例题：[leetcode 541 反转字符串 II](https://leetcode.cn/problems/reverse-string-ii/description/)

按题目模拟即可。

```cpp
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        for (int i = 0; i < s.size(); i += 2 * k)
        {
            if (s.size() - i >= k)
            {
                // 从i开始计，剩余的字符至少有k个
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else
            {
                // 不足k个字符
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};
```

时间复杂度: O(n)，空间复杂度: O(1)
