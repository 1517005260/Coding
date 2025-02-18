/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution
{
private:
    vector<vector<string>> _res;
    vector<string> _tmp;

    void dfs(string &s, int startIdx)
    {
        if (startIdx == s.size())
        {
            _res.push_back(_tmp);
            return;
        }

        for (int i = startIdx; i < s.size(); i++)
        {
            // 如果本字串是回文串，那么加入_tmp
            if (flag(s, startIdx, i))
            {
                string sub = s.substr(startIdx, i - startIdx + 1);
                _tmp.push_back(sub);
            }
            else
            {
                continue;
            }

            dfs(s, i + 1);
            _tmp.pop_back();
        }
    }

    bool flag(string &s, int start, int end)
    {
        // 回文串判断
        for (int i = start, j = end; i < j; i++, j--)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s)
    {
        dfs(s, 0);
        return _res;
    }
};
// @lc code=end
