/*
 * @lc app=leetcode.cn id=123 lang=cpp
 * @lcpr version=30100
 *
 * [123] 买卖股票的最佳时机 III
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

        vector<vector<int>> dp(n, vector<int>(5, 0));

        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        dp[0][3] = -prices[0];
        dp[0][4] = 0;

        for (int i = 1; i < n; i++)
        {
            // 不操作
            dp[i][0] = 0;

            // 第一次买入
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);

            // 第一次卖出
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);

            // 第二次买入
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);

            // 第二次卖出
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }

        return max(dp[n - 1][0], max(dp[n - 1][2], dp[n - 1][4]));
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,3,5,0,0,3,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
