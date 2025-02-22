/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int cnt = 0;

        int s_idx = s.size() - 1;
        for (int g_idx = g.size() - 1; g_idx >= 0; g_idx--)
        {
            if (s_idx >= 0 && s[s_idx] >= g[g_idx])
            {
                // 发现可以满足胃口
                cnt++;
                s_idx--;
            }
        }

        return cnt;
    }
};
// @lc code=end
