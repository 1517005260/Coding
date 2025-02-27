/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution
{

public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end(), cmp);

        res.push_back(intervals[0]); // 先放入第一个区间，后续进行合并

        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> &last = res.back();
            // 如果有重叠区间
            // 即上一个区间的右边大于等于这一个区间的左边
            if (last[1] >= intervals[i][0])
            {
                last[1] = max(intervals[i][1], last[1]);
            }
            else
            {
                // 非重叠区间
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};
// @lc code=end
