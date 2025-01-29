/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int alphabet[26] = {0};
        if (ransomNote.size() > magazine.size())
        {
            return false;
        }

        for (int i = 0; i < magazine.size(); i++)
        {
            alphabet[magazine[i] - 'a']++;
        }

        for (int i = 0; i < ransomNote.size(); i++)
        {
            alphabet[ransomNote[i] - 'a']--;
            // ransomNote可以不用magazine中的字母
            // 所以alphabet的元素可以大于等于0，但不能小于0
            if (alphabet[ransomNote[i] - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
