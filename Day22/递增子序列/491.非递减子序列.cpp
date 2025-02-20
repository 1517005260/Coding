/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> res;
    vector<int> tmp;

    void dfs(vector<int> &nums, int startIdx)
    {
        if (tmp.size() >= 2)
        {
            res.push_back(tmp); // 根据题目要求，至少有两个元素
        }

        int used[201] = {0}; // 算法竞赛做法，这里有-100~100共201个数字
                             // 建立映射：-100 用过了，则used[0] = 1
        for (int i = startIdx; i < nums.size(); i++)
        {
            // 如果当前tmp非空且选中的元素非递增，或者选中重复元素，则跳过
            if ((!tmp.empty() && tmp.back() > nums[i]) || used[nums[i] + 100] == 1)
            {
                continue;
            }

            used[nums[i] + 100] = 1;
            tmp.push_back(nums[i]);
            dfs(nums, i + 1);
            tmp.pop_back();
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        dfs(nums, 0);
        return res;
    }
};
// @lc code=end
