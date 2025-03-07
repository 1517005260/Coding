/*
 * @lc app=leetcode.cn id=377 lang=cpp
 * @lcpr version=30100
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        // 本题有用int会溢出的数据
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++)
        {
            for (int n : nums)
            {
                if (i >= n)
                {
                    // n = nums[j]
                    dp[i] += dp[i - n];
                }
            }
        }

        return dp[target];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [9]\n3\n
// @lcpr case=end

 */
