# 买卖股票的最佳时机

例题：[leetcode 121 买卖股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/)

1. `dp[i][j]`的含义：

- 第 i 天结束时，`dp[i][0]`表示没有持有股票的最大利润
- 第 i 天结束时，`dp[i][1]`表示持有股票的最大利润

即：i 是天数，j 是状态

2. 递推公式：

对于`dp[i][0]`，我们要么保持不持有的状态，要么是卖掉了股票，所以，最大利润为：

`dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])`

对于`dp[i][1]`，我们要么保持持有的状态，要么是买入了股票，所以，最大利润为：

`dp[i][1] = max(dp[i-1][1], -prices[i])`

注意这里现金流为负数，因为是刚刚买入了股票，还未卖出盈利

3. 初始化：

```
dp[0][0] = 0 // 开始时未持有股票
dp[0][1] = -prices[0] // 开始时直接买入股票
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
            return 0; // 不能卖出股票
        }

        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
        }

        return dp[n - 1][0]; // 最后一天需要卖掉股票
    }
};
```

5. 空间复杂度优化：

我们发现，第 i 天的最大利润只依靠于第 i-1 天的状态。所以只需要两个变量记录即可：

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

        int noStock = 0;
        int hasStock = -prices[0];

        for (int i = 1; i < n; i++)
        {
            noStock = max(noStock, hasStock + prices[i]);
            hasStock = max(hasStock, -prices[i]);
        }

        return noStock;
    }
};
```
