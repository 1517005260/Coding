/*
 * @lc app=leetcode.cn id=674 lang=cpp
 * @lcpr version=30101
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
        {
            return n;
        }

        vector<int> dp(n, 1);

        int res = 1;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                dp[i] = max(dp[i], dp[i - 1] + 1);
            }

            res = max(dp[i], res);
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,5,4,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n
// @lcpr case=end

 */
