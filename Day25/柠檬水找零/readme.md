# 柠檬水找零

例题：[leetcode 860 柠檬水找零](https://leetcode.cn/problems/lemonade-change/description/)

找零情况分析：

- 付 5，不需要找零
- 付 10，需要找 5
- 付 20：找 3 个 5 或者一个 10 一个 5

综上，5 更万能一点，需要省着用

```cpp
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0, ten = 0, twenty = 0; // 记录5，10，20的数量

        for (int bill : bills)
        {
            if (bill == 5)
            {
                five++;
                continue;
            }

            if (bill == 10)
            {
                if (five > 0)
                {
                    five--;
                    ten++;
                }
                else
                {
                    return false;
                }
                continue;
            }

            if (bill == 20)
            {
                // 因为5更珍贵，所以我们优先去消耗10
                if (ten > 0 && five > 0)
                {
                    ten--;
                    five--;
                    twenty++;
                }
                else if (five >= 3)
                {
                    five -= 3;
                    twenty++;
                }
                else
                {
                    return false;
                }
                continue;
            }
        }

        return true;
    }
};
```
