/*
 * @lc app=leetcode.cn id=115 lang=cpp
 * @lcpr version=30103
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = s.size(), n = t.size();

        vector<vector<uint64_t>> dp(m + 1, vector<uint64_t>(n + 1, 0));

        // 初始化
        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = 1;
        }

        // dp
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // 如果当前字符相等
                // 要么用当前字符匹配，要么不用当前字符匹配
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    // 当前字符串不相等
                    // 只能用s前面的部分进行匹配
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

/*
// @lcpr case=start
// "rabbbit"\n"rabbit"\n
// @lcpr case=end

// @lcpr case=start
// "babgbag"\n"bag"\n
// @lcpr case=end

 */
