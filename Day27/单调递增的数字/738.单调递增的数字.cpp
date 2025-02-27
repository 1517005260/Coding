/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        string num = to_string(n);

        int idx = num.size(); // 从idx开始，后面的数字都应该变成9
        for (int i = num.size() - 1; i > 0; i--)
        {
            if (num[i] < num[i - 1])
            {
                num[i - 1]--;
                idx = i;
            }
        }

        // 全变成9
        for (int i = idx; i < num.size(); i++)
        {
            num[i] = '9';
        }

        return stoi(num);
    }
};
// @lc code=end
