# 无重叠区间

例题：[leetcode 435 无重叠区间](https://leetcode.cn/problems/non-overlapping-intervals/description/)

和[上题](../用最少数量的箭引爆气球/)基本类似，引爆的箭数可以认为是非重叠区间的个数。只不过上道题中，`[1,2]`和`[2,3]`是可以一起引爆的，这道题它们是不算做重叠的。

```cpp
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
```
