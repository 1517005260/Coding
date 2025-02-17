/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> _res;
    vector<int> _tmp;

    void dfs(int k, int targetSum, int startIdx)
    {
        if (_tmp.size() == k)
        {
            if (targetSum == 0)
            {
                _res.push_back(_tmp);
            }
            return;
        }

        for (int i = startIdx; i <= 9 - (k - _tmp.size()) + 1; i++) // 同上题的剪枝操作
        {
            targetSum -= i;
            _tmp.push_back(i);
            dfs(k, targetSum, i + 1);
            _tmp.pop_back();
            targetSum += i;
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        dfs(k, n, 1);
        return _res;
    }
};
// @lc code=end
