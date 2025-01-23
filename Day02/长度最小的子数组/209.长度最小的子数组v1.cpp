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
        int res = INT32_MAX; // 32位下最大int
        int sum = 0;         // 子数组的和，需要令其等于target
        int len = 0;         // 子数组的长度，需要令其最小
        for (int i = 0; i < nums.size(); i++)
        {
            sum = 0; // 每次遍历重置sum
            for (int j = i; j < nums.size(); j++)
            {
                // 向后遍历子数组
                sum += nums[j];
                if (sum >= target)
                {
                    len = j - i + 1;
                    res = res < len ? res : len;
                    break;
                }
            }
        }

        if (res == INT32_MAX)
        {
            return 0;
        }
        else
        {
            return res;
        }
    }
};
// @lc code=end
