/*
 * @lc app=leetcode.cn id=72 lang=cpp
 * @lcpr version=30103
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // 初始化
        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++)
        {
            dp[0][j] = j;
        }

        // dp
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    // 需要进行增删改的操作
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

/*
// @lcpr case=start
// "horse"\n"ros"\n
// @lcpr case=end

// @lcpr case=start
// "intention"\n"execution"\n
// @lcpr case=end

 */
