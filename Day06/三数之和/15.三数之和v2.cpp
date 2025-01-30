/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        // 遍历a
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                break;
            }

            // 跳过重复的a
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            // b = nums[left]; c = nums[right]
            // 如果 a+b+c > 0，说明和大了，right指针需要向左移动
            // 如果 a+b+c < 0，说明和小了，left指针需要向右移动

            while (right > left) // 下标不能重复
            {
                if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else
                {
                    // 找到了符合条件的三元组
                    res.push_back({nums[i], nums[left], nums[right]});

                    // 找到后开始对b和c去重
                    // 如果找到前就开始去重会漏 0 0 0的情况
                    while (right > left && nums[right] == nums[right - 1])
                        right--;
                    while (right > left && nums[left] == nums[left + 1])
                        left++;

                    // 更新right和left，寻找相同a下的不同bc
                    right--;
                    left++;
                }
            }
        }

        return res;
    }
};
// @lc code=end
