# 判断子序列

例题：[leetcode 392 判断子序列](https://leetcode.cn/problems/is-subsequence/description/)

## 双指针解法

对短的字符串使用慢指针 i，长的字符串使用快指针 j，如果`s[i] == t[j]`，那么 i 就可以向后移动。最后若 i 移到了 s 的尾部，则 true

```cpp
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0, j = 0;

        while (i < s.size() && j < t.size())
        {
            // 尝试移动慢指针
            if (s[i] == t[j])
            {
                i++;
            }

            // 快指针移动
            j++;
        }
        // 最后如果是子串，i还会向后移动一位
        return i == s.size();
    }
};
```

## 动态规划解法

还是最长公共子序列的思路：令 `dp[i][j]` 表示 s 的前 i 个字符（`s[i-1]`）和 t 的前 j 个字符（`t[j-1]`）的最长公共子序列的长度。

递推公式：

```
如果目前两个字符相等，那么最长公共子序列可以延长一位
dp[i][j] = dp[i-1][j-1] + 1

如果目前两个字符不等，那么最长公共子序列需由两边推出：
dp[i][j] = max(dp[i-1][j], dp[i][j-1])
```

最后如果这个`dp[i][j] == s的长度`，那么即为 true

```cpp
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[s.size()][t.size()] == s.size();
    }
};
```
