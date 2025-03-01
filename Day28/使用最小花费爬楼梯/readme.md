# 使用最小花费爬楼梯

例题：[leetcode 746 使用最小花费爬楼梯](https://leetcode.cn/problems/min-cost-climbing-stairs/description/)

1. `dp[i]`的含义：到第 i 层的最小花费为`dp[i]`

2. 递推公式：

由上题[爬楼梯](../爬楼梯/)，我们爬上一层楼梯一共有两种方法：或是从 i-1 层走一步，或是从 i-2 层走两步。因此：

```
走到i-1层的最小花费：dp[i-1]
i-1层走一步的花费：cost[i-1]

走到i-2层的最小花费：dp[i-2]
i-2层走两步的花费：cost[i-2]

所以dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2])
```

3. 初始化：我们可以从 i=0 或 i=1 的台阶开始爬，即到 i=0 或 i=1 的花费为 0

4. 遍历顺序：从前向后

```cpp
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1);

        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }
};
```
