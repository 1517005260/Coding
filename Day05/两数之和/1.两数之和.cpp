/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map; // 存放<元素，下标>
        for (int i = 0; i < nums.size(); i++)
        {
            auto item = map.find(target - nums[i]);
            if (item != map.end())
            {
                // map 中存在 target - nums[i]，即可以配对
                return {item->second, i}; // 返回配对的下标
            }
            else
            {
                // map 中不存在 target - nums[i]，无法配对，但可以将nums[i]加入map以待后续匹配
                map.insert(pair<int, int>(nums[i], i));
            }
        }
        return {};
    }
};
// @lc code=end
