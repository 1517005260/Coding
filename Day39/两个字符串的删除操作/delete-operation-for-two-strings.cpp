/*
 * @lc app=leetcode.cn id=583 lang=cpp
 * @lcpr version=30103
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
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
// @lc code=end

/*
// @lcpr case=start
// "sea"\n"eat"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"etco"\n
// @lcpr case=end

 */
