/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (nums[middle] > target)
            {
                right = middle - 1;
            }
            else if (nums[middle] < target)
            {
                left = middle + 1;
            }
            else if (nums[middle] == target)
            {
                return middle; //  找到时的情况，不需要插入
            }
        }
        // 没有找到，需要插入
        return left; // left 总是指向第一个大于等于 target 的位置
    }
};
// @lc code=end
