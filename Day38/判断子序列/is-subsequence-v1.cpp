/*
 * @lc app=leetcode.cn id=392 lang=cpp
 * @lcpr version=30101
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0, j = 0;

        while (i < s.size() && j < t.size())
        {
            // 尝试移动慢指针
            if (s[i] == t[j])
            {
                i++;
            }

            // 快指针移动
            j++;
        }
        // 最后如果是子串，i还会向后移动一位
        return i == s.size();
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abc"\n"ahbgdc"\n
// @lcpr case=end

// @lcpr case=start
// "axc"\n"ahbgdc"\n
// @lcpr case=end

 */
