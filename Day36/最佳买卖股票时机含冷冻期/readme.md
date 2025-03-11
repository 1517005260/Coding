# 最佳买卖股票时机含冷冻期

例题：[leetcode 309 最佳买卖股票时机含冷冻期](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/)

本题是[Ⅱ](../../Day35/买卖股票的最佳时机%20Ⅱ/)的变式，卖出股票后会有一天的冷冻期

![png](https://code-thinking-1253855093.file.myqcloud.com/pics/518d5baaf33f4b2698064f8efb42edbf.png)

如图的状态转移，我们定义如下状态：

```
0: 持有股票态，可以是今天买入，也可以是一直持有
1: 不持有股票，不处于冷冻期。可以是两天前卖了股票，也可以是一直不持有
2: 今天卖出股票，即将进入冷冻期
3: 今天是冷冻期，明天解冻
```

由于冷冻期**只能由前一天卖出股票推出**，所以需要单独给个状态

1. `dp[i][j]`含义：第 i 天的 j 状态

2. 递推公式：

```
持有股票态，1）前一天就持有 2） 前一天是冷冻期，今天买入 3）前一天不是冷冻期，今天买入
dp[i][0] = max(dp[i-1][0], max(dp[i-1][3], dp[i-1][1]) - prices[i])

不持有股票且非冷冻期，1）维持前一天的状态 2）前一天冷冻期，今天解冻且不买入
dp[i][1] = max(dp[i-1][1], dp[i-1][3])

今天卖出股票，只能由持有股票的状态转移来
dp[i][2] = dp[i-1][0] + prices[i]

今天是冷冻期，只能由卖出股票的状态转移来
dp[i][3] = dp[i-1][2]
```

3. 初始化：

首天不能卖出股票：

```
dp[i][0] = -prices[0]
dp[i][1] = 0
```

4. 遍历顺序：遍历 i 即可

```cpp
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1)
        {
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][0] = -prices[0];

        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3], dp[i - 1][1]) - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }
        // 三种不持有股票状态的最大值
        return max(dp[n - 1][1], max(dp[n - 1][2], dp[n - 1][3]));
    }
};
```
