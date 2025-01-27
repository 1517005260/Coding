/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // 0-a, 1-b, 2-c,... 以此类推
        int alphabet[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            alphabet[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            alphabet[t[i] - 'a']--;
        }

        // 如果是字母异位词，那么alphabet[26]应该全0
        for (int i = 0; i < 26; i++)
        {
            if (alphabet[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
