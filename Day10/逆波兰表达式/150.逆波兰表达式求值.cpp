/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        // leetcode 测试数据有longlong
        stack<long long> s;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                long long num2 = s.top();
                s.pop();
                long long num1 = s.top();
                s.pop();

                if (tokens[i] == "+")
                {
                    s.push(num1 + num2);
                }
                else if (tokens[i] == "-")
                {
                    s.push(num1 - num2);
                }
                else if (tokens[i] == "*")
                {
                    s.push(num1 * num2);
                }
                else
                {
                    s.push(num1 / num2);
                }
            }
            else
            {
                s.push(stoll(tokens[i])); // string to long long
            }
        }
        long long res = s.top();
        return (int)res;
    }
};
// @lc code=end
