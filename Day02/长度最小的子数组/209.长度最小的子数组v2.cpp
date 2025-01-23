/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int res = INT32_MAX;
        int sum = 0;
        int i = 0; // 滑动窗口的起始位置
        int len = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            // 调整滑动窗口的末尾
            sum += nums[j];

            // 尝试缩小滑动窗口
            while (sum >= target)
            {
                len = j - i + 1;
                res = res < len ? res : len;
                sum -= nums[i];
                i++;
            }
        }

        return res == INT32_MAX ? 0 : res;
    }
};
// @lc code=end
