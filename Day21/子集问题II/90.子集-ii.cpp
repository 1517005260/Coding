/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> _res;
    vector<int> _tmp;

    void dfs(vector<int> &nums, int startIdx)
    {
        _res.push_back(_tmp);

        for (int i = startIdx; i < nums.size(); i++)
        {
            if (i > startIdx && nums[i] == nums[i - 1])
            {
                continue;
            }

            _tmp.push_back(nums[i]);
            dfs(nums, i + 1);
            _tmp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return _res;
    }
};
// @lc code=end
