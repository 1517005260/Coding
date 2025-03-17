# 两个字符串的删除操作

例题：[leetcode 583 两个字符串的删除操作](https://leetcode.cn/problems/delete-operation-for-two-strings/description/)

本题的言外之意，就是要找到两个 word 的[最长公共子序列](../../Day38/最长公共子序列/)，其他的部分都是需要删除的。

```cpp
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int res = 0;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                res = max(res, dp[i][j]);
            }
        }

        // res 就是最长公共子序列的长度
        // 剩下的都要删掉
        return (m - res) + (n - res);
    }
};
```
