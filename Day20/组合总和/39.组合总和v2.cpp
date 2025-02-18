/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> _res;
    vector<int> _tmp;

    void dfs(vector<int> &candidates, int target, int startIdx)
    {
        if (target < 0)
        {
            return;
        }
        if (target == 0)
        {
            _res.push_back(_tmp);
            return;
        }

        // 进行剪枝优化
        for (int i = startIdx; i < candidates.size() && target - candidates[i] >= 0; i++)
        {
            target -= candidates[i];
            _tmp.push_back(candidates[i]);
            dfs(candidates, target, i);
            _tmp.pop_back();
            target += candidates[i];
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return _res;
    }
};
// @lc code=end
