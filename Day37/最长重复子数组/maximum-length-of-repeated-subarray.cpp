/*
 * @lc app=leetcode.cn id=718 lang=cpp
 * @lcpr version=30101
 *
 * [718] 最长重复子数组
 */

// @lc code=start
class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        int res = 0;

        // 初始化，判断单个元素相等的情况
        for (int j = 0; j < n; j++)
        {
            if (nums1[0] == nums2[j])
            {
                dp[0][j] = 1;
                res = 1;
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (nums1[i] == nums2[0])
            {
                dp[i][0] = 1;
                res = 1;
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,2,1]\n[3,2,1,4,7]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0,0,0]\n[0,0,0,0,0]\n
// @lcpr case=end

 */
