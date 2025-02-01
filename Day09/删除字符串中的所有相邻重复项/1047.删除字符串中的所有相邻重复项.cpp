/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> mirror;
        for (int i = 0; i < s.size(); i++)
        {
            if (mirror.empty() || mirror.top() != s[i])
            {
                mirror.push(s[i]);
            }
            else
            {
                // mirror.top()==s[i]
                mirror.pop();
            }
        }

        // 将栈变成字符串
        string res = "";
        while (!mirror.empty())
        {
            res += mirror.top();
            mirror.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
