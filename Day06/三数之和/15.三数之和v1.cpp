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
        // 先对nums排序，方便后续操作
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) // 遍历a
        {
            // 由于我们已经对nums排序过，所以如果nums[i] > 0，后续不可能出现三数之和等于0的情况
            // 同示例2
            if (nums[i] > 0)
            {
                break;
            }

            // 跳过重复的a
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            // 开始找b和c
            unordered_set<int> set_b; // 存放不重复的b
            for (int j = i + 1; j < nums.size(); j++)
            {
                // 去重b=c的情况
                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2])
                {
                    // 跳过相同的三个数，仅保留一个
                    // 例如 -2 0 0 0 2，保留 -2 0(第一个0) 2
                    continue;
                }

                int index = 0 - (nums[i] + nums[j]);
                // 现在需要动态收集b和c
                if (set_b.find(index) != set_b.end())
                {
                    // 如果集合b中有index，即返回 nums[i] index nums[j]
                    res.push_back({nums[i], index, nums[j]}); // 这里index作为b
                    set_b.erase(index);                       // 删除已经用过的b值，避免重复使用
                }
                else
                {
                    // 如果集合b中没有index，那么就吧nums[j]插入set_b作为b，供后续查找
                    set_b.insert(nums[j]);
                }
            }
        }
        return res;
    }
};
// @lc code=end
