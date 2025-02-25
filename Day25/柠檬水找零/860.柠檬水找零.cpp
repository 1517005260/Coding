/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
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
// @lc code=end
