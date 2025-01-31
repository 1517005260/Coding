/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        // haystack 是主串
        // needle 是模式串
        int pattern_len = needle.size();

        // 合并串
        string str = needle + '#' + haystack;
        // π 数组
        vector<int> pi(str.size());
        for (int i = 1; i < str.size(); i++)
        {
            int len = pi[i - 1];
            while (len != 0 && str[i] != str[len])
            {
                len = pi[len - 1];
            }
            if (str[i] == str[len])
            {
                pi[i] = len + 1;

                // 匹配成功
                if (pi[i] == pattern_len)
                {
                    return i - pattern_len * 2; // i是合并串里的下标，还要注意减掉合并串中的模式串前缀。
                }
            }
        }
        return -1;
    }
};
// @lc code=end
