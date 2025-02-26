# 用最少数量的箭引爆气球

例题：[leetcode 452 用最少数量的箭引爆气球](https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/description/)

points 数组指定了气球存在的区间，气球没有纵坐标，我们需要用最少的箭数引爆气球。

![png](https://code-thinking-1253855093.file.myqcloud.com/pics/20201123101929791.png)

如图，我们需要尽量寻找最右边的边界，这样射的箭数才能最少。

此外，注意`[1,2]`和`[2,3]`是可以一起引爆的，只要射向 2 即可。

```cpp
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (!points.size())
        {
            return 0;
        }

        // 先将points数组递增排序
        sort(points.begin(), points.end(), cmp);

        int cnt = 1; // 如果points非空，即至少有一个气球，我们需要一只箭
        for (int i = 1; i < points.size(); i++)
        {
            // [1,2] 和 [2,3] 是可以一起引爆的，[1,2] 和 [3,4]需要两次引爆
            if (points[i - 1][1] < points[i][0])
            {
                // 如上例，这是2<3的情况
                cnt++;
            }
            else
            {
                // 接下来需要找到最小重叠右边界，使得能一箭双雕
                // [1,4] [2,3] => [2,3] 才能一件双雕
                // [1,2] [2,3] => [2] 才能一箭双雕
                points[i][1] = min(points[i][1], points[i - 1][1]);
            }
        }
        return cnt;
    }
};
```
