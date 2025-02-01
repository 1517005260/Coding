# 有效的括号

例题：[leetcode 20 有效的括号](https://leetcode.cn/problems/valid-parentheses/description/)

思路：每次碰到左括号，就把右括号放入栈中。碰到右括号，就 pop

- 情况一：左括号多于右括号，即最后匹配完栈不空
- 情况二：左括号少于右括号，即在遍历过程中发现栈空
- 情况三：左右括号不匹配，即栈中无符合要求的元素

原理如下：

![gif](https://code-thinking.cdn.bcebos.com/gifs/20.%E6%9C%89%E6%95%88%E6%8B%AC%E5%8F%B7.gif)

```cpp
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
```

时间复杂度: O(n)，空间复杂度: O(n)
