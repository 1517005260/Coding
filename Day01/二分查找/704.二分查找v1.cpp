/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1; // 数组 0~n-1
        while (left <= right)        // [left, right]
        {
            int middle = (left + right) / 2;
            if (target > nums[middle])
            {
                left = middle + 1;
            }
            else if (target < nums[middle])
            {
                right = middle - 1;
            }
            else
            {
                return middle;
            }
        }
        return -1;
    }
};
// @lc code=end
