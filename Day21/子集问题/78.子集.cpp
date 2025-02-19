/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
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

        // 这里不需要特判return，因为包含在for循环条件里了
        for (int i = startIdx; i < nums.size(); i++)
        {
            _tmp.push_back(nums[i]);
            dfs(nums, i + 1);
            _tmp.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return _res;
    }
};
// @lc code=end
