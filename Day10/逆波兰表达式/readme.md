# 逆波兰表达式

例题：[leetcode 150 逆波兰表达式](https://leetcode.cn/problems/evaluate-reverse-polish-notation/description/)

即后缀表达式，`( 1 + 2 ) * ( 3 + 4 )` => `1 2 + 3 4 + *`，栈的经典应用

动画如下：

![gif](https://code-thinking.cdn.bcebos.com/gifs/150.%E9%80%86%E6%B3%A2%E5%85%B0%E8%A1%A8%E8%BE%BE%E5%BC%8F%E6%B1%82%E5%80%BC.gif)

即每次遇到数字就压栈，每次遇到符号就取两个栈中数计算，算完后再压栈

注意计算顺序是栈中第二个元素在前面，栈的 top 在后面

```cpp
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
```

时间复杂度: O(n)，空间复杂度: O(n)
