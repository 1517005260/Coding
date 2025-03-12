/*
 * @lc app=leetcode.cn id=300 lang=cpp
 * @lcpr version=30101
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();

        if (n <= 1)
        {
            return n;
        }

        vector<int> dp(n, 1);

        int res = 1; // 递增子序列的长度至少为1
        // 使用res的原因是，dp[i]的定义是以nums[i]结尾的最长递增子序列
        // 而整个数组的最长递增子序列不一定以nums[i]结尾

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [10,9,2,5,3,7,101,18]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7,7,7,7]\n
// @lcpr case=end

 */
