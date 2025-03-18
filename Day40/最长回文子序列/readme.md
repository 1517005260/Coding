# 最长回文子序列

例题：[leetcode 516 最长回文子序列](https://leetcode.cn/problems/longest-palindromic-subsequence/description/)

**回文子串是连续的，回文子序列可以不连续**

1. `dp[i][j]`表示在`[i, j]`区间内的最长回文子序列长度

2. 递推公式：

![jpg](https://code-thinking-1253855093.file.myqcloud.com/pics/20210127151350563.jpg)

- 当`s[i] == s[j]`时，说明两端的字符可以同时包含在回文中，因此长度增加`2`：

  ```
  dp[i][j] = dp[i + 1][j - 1] + 2;
  ```

![jpg](https://code-thinking-1253855093.file.myqcloud.com/pics/20210127151420476.jpg)

- 当`s[i] != s[j]`时，两端的字符不能同时选，所以长度取左右两个子问题的最大值，即分别讨论去除`s[i]`或`s[j]`：

  ```
  dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
  ```

3. 初始情况：单个字符本身就是回文串，因此`dp[i][i] = 1`。

4. 遍历顺序：i 从大到小，j 从小到大

```cpp
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        // s[0 ~ n-1]
        return dp[0][n - 1];
    }
};
```
