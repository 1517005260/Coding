/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> _res; // 总共结果
    vector<int> _tmp;         // 单次结果

    // 根据模板写即可
    void dfs(int n, int k, int startIdx)
    {
        if (_tmp.size() == k)
        {
            _res.push_back(_tmp);
            return;
        }

        for (int i = startIdx; i <= n; i++)
        {
            _tmp.push_back(i);
            dfs(n, k, i + 1);
            _tmp.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        dfs(n, k, 1);
        return _res;
    }
};
// @lc code=end
