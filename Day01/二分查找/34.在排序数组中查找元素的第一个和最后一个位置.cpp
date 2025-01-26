/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = get_left(nums, target);
        int right = get_right(nums, target);

        // 已经拿到左右边界，理想情况应该返回[left + 1, right -1]
        // 但是存在以下三种情况：

        // 1. target 在数组的左边界以外/右边界以外
        // 此时，get_right 和 get_left 永远不会被更新
        if (left == -2 || right == -2)
        {
            return {-1, -1};
        }

        // 2. 理想情况，命中target
        if (right - left > 1) // 边界有效
        {
            return {left + 1, right - 1};
        }

        // 3. target 在数组范围内，但是未找到
        return {-1, -1};
    }

    // target 的右边界的下一个位置
    int get_right(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int get_right = -2; // 用于区分三种情况
        while (left <= right)
        {
            // 标准二分写法
            int middle = (left + right) / 2;
            if (target < nums[middle])
            {
                // 1 1 2 2 3 , target = 1 < nums[middle] = 2
                right = middle - 1;
            }
            else
            {
                // 1 1 2 2 3, target = 2 >= nums[middle] = 2
                left = middle + 1; // middle = 2, left = 3
                get_right = left;  // 迭代后left = 4
            }
        }
        return get_right;
    }

    int get_left(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int get_left = -2;
        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (target > nums[middle])
            {
                // 1 1 2 2 3 , target = 3 > nums[middle] = 2
                left = middle + 1;
            }
            else
            {
                // 1 1 2 2 3 , target = 2 >= nums[middle] = 2
                right = middle - 1; // middle = 2, right = 1
                get_left = right;
            }
        }
        return get_left;
    }
};
// @lc code=end
