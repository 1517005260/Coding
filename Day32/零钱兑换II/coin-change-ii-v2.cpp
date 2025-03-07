/*
 * @lc app=leetcode.cn id=518 lang=cpp
 * @lcpr version=30100
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();

        vector<uint64_t> dp(amount + 1, 0);

        dp[0] = 1; // 凑成0的组合数只有1种

        for (int i = 0; i < n; i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                dp[j] += dp[j - coins[i]];
            }
        }

        return dp[amount];
    }
};
// @lc code=end

/*
// @lcpr case=start
// 5\n[1, 2, 5]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[2]\n
// @lcpr case=end

// @lcpr case=start
// 10\n[10]\n
// @lcpr case=end

 */
