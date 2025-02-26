/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int map[26] = {0}; // 统计26个字母出现在的最后位置
        for (int i = 0; i < s.size(); i++)
        {
            map[s[i] - 'a'] = i;
        }

        vector<int> res;

        int left = 0;  // 左边界
        int right = 0; // 右边界
        for (int i = 0; i < s.size(); i++)
        {
            // 更新最大右边界
            right = max(right, map[s[i] - 'a']);

            if (i == right)
            {
                res.push_back(right - left + 1);
                // 更新左边界
                left = i + 1;
            }
        }

        return res;
    }
};
// @lc code=end
