/*
 * @lc app=leetcode.cn id=322 lang=cpp
 * @lcpr version=30100
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 100); // 初始化成较大值
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            for (int coin : coins)
            {
                if (i >= coin)
                {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // 如果dp[amount]仍然是amount+100，说明没有能组成它的方法
        if (dp[amount] == amount + 100)
        {
            return -1;
        }
        return dp[amount];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1, 2, 5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */
