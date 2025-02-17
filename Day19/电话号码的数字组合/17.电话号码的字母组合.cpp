/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution
{
private:
    // 空定义 0，1 是为了让 map[2] 就指向2
    const string map[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz", // 9
    };

    vector<string> _res;
    string s;

    // idx表示给定digits的下标
    void dfs(string &digits, int idx)
    {
        if (idx == digits.size())
        {
            _res.push_back(s);
            return;
        }

        // 取出digits[idx]对应的字母
        string letters = map[digits[idx] - '0'];
        for (int i = 0; i < letters.size(); i++)
        {
            s.push_back(letters[i]);
            dfs(digits, idx + 1);
            s.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (!digits.size())
        {
            return _res;
        }
        dfs(digits, 0);
        return _res;
    }
};
// @lc code=end
