/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        // 首先根据模板求解pi数组
        vector<int> pi(s.size());
        for (int i = 1; i < s.size(); i++)
        {
            int len = pi[i - 1];
            while (len != 0 && s[i] != s[len])
            {
                len = pi[len - 1];
            }
            if (s[i] == s[len])
            {
                pi[i] = len + 1;
            }
        }

        int n = s.size();
        int L = pi[n - 1];
        if (L != 0 && n % (n - L) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// @lc code=end
