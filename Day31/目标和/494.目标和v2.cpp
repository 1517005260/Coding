/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int num : nums)
        {
            sum += num;
        }

        if (abs(target) > sum || (sum + target) % 2 == 1)
        {
            return 0;
        }

        int positive = (sum + target) / 2;

        vector<int> dp(positive + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = positive; j >= nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[positive];
    }
};
// @lc code=end
