/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        // 长度一定是偶数
        if (s.size() % 2)
        {
            return false;
        }

        // 栈存储左括号对应的右括号
        stack<char> right;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                right.push(')');
            }
            else if (s[i] == '{')
            {
                right.push('}');
            }
            else if (s[i] == '[')
            {
                right.push(']');
            }
            else if (right.empty())
            {
                return false; // 如果在遍历过程中栈空了，返回false
            }
            else if (s[i] != right.top())
            {
                return false; // 如果不匹配，返回false
            }
            else
            {
                // 匹配了
                right.pop();
            }
        }

        // 如果匹配结束，栈不空，也不匹配
        return right.empty();
    }
};
// @lc code=end
