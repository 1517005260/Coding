/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }

    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (!intervals.size())
        {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), cmp);

        int cnt = 1;
        for (int i = 1; i < intervals.size(); i++)
        {
            // [1,2] 和 [2,3] 需要两次引爆
            // 即cnt记录非重叠区间的个数
            if (intervals[i - 1][1] <= intervals[i][0])
            {
                cnt++;
            }
            else
            {
                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
            }
        }

        return intervals.size() - cnt;
    }
};
// @lc code=end
