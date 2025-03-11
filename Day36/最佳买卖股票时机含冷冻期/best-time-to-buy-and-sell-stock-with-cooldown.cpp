/*
 * @lc app=leetcode.cn id=309 lang=cpp
 * @lcpr version=30101
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1)
        {
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][0] = -prices[0];

        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3], dp[i - 1][1]) - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }
        // 三种不持有股票状态的最大值
        return max(dp[n - 1][1], max(dp[n - 1][2], dp[n - 1][3]));
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
