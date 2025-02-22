/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> res;
    vector<int> tmp;
    int used[8] = {0};

    void dfs(vector<int> &nums)
    {
        if (tmp.size() == nums.size())
        {
            res.push_back(tmp);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            // 1. 当前数字已使用过，跳过
            // 2. 当前数字与前一个数字相同，且前一个数字未使用，跳过 => 相同数字的使用是有序的
            if (used[i] == 1 || i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0)
            {
                continue;
            }

            used[i] = 1;
            tmp.push_back(nums[i]);
            dfs(nums);
            tmp.pop_back();
            used[i] = 0;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        dfs(nums);
        return res;
    }
};
// @lc code=end
