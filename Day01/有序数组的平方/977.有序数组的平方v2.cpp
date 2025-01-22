/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int k = nums.size() - 1;
        vector<int> res(nums.size(), 0);
        for (int i = 0, j = nums.size() - 1; i <= j;)
        {
            if (abs(nums[i]) > abs(nums[j]))
            {
                res[k] = nums[i] * nums[i];
                k--;
                i++;
            }
            else
            {
                res[k] = nums[j] * nums[j];
                k--;
                j--;
            }
        }
        return res;
    }
};
// @lc code=end
