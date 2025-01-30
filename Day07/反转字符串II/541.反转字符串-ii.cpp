/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        for (int i = 0; i < s.size(); i += 2 * k)
        {
            if (s.size() - i >= k)
            {
                // 从i开始计，剩余的字符至少有k个
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else
            {
                // 不足k个字符
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};
// @lc code=end
