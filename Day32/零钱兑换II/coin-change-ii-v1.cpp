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
        // 本题用int会溢出
        vector<vector<uint64_t>> dp(n, vector<uint64_t>(amount + 1));

        // 初始化dp
        // 1. amount = 0 时，凑成0元的情况只有一个都不选才行
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }

        // 2. n=0时，仅使用第一个硬币的情况，只有amount是第一个硬币的倍数的时候才有一种方法
        for (int j = 0; j <= amount; j++)
        {
            if (j % coins[0] == 0)
            {
                dp[0][j] = 1;
            }
            else
            {
                dp[0][j] = 0;
            }
        }

        // dp 过程
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                if (j < coins[i])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    // 本题是组合，不是求max
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
                }
            }
        }

        return dp[n - 1][amount];
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
