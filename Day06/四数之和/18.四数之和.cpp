/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        // 多套一层j循环
        for (int j = 0; j < nums.size(); j++)
        {
            // 剪枝处理，需要确保相加的不是负数才能剪枝
            if (nums[j] > target && nums[j] >= 0)
            {
                break;
            }

            // nums[j]去重
            if (j > 0 && nums[j] == nums[j - 1])
            {
                continue;
            }

            // 三数之和的代码：
            for (int i = j + 1; i < nums.size(); i++)
            {
                if (nums[j] + nums[i] > target && nums[j] + nums[i] >= 0)
                {
                    break;
                }

                if (i > j + 1 && nums[i] == nums[i - 1])
                {
                    continue;
                }

                int left = i + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    // 防止溢出
                    long sum = (long)nums[j] + (long)nums[i] + (long)nums[left] + (long)nums[right];
                    if (sum > target)
                    {
                        right--;
                    }
                    else if (sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        res.push_back({nums[j], nums[i], nums[left], nums[right]});

                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        while (left < right && nums[left] == nums[left + 1])
                            left++;

                        right--;
                        left++;
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end
