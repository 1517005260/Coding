# 合并区间

例题：[leetcode 56 合并区间](https://leetcode.cn/problems/merge-intervals/)

本题也是重叠区间问题，这里`[1,2]`和`[2,3]`可以并为`[1,3]`

![png](https://code-thinking-1253855093.file.myqcloud.com/pics/20201223200632791.png)

如图，我们把所有区间按照左边排序后，如果下一个区间的左边界小于上一个区间的右边界，则有重合的部分。

```cpp
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
```

注意 last 是引用，我们需要修改实际的 res.back()
