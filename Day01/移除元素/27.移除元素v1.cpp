/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == val)
            {
                // 将 i 以后的所有元素向前移动
                for (int j = i + 1; j < size; j++)
                {
                    nums[j - 1] = nums[j];
                }
                // 更新 nums 数组
                i--;
                size--;
            }
        }
        return size;
    }
};
// @lc code=end
