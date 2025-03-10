# 买卖股票的最佳时机 Ⅱ

例题：[leetcode 122 买卖股票的最佳时机 Ⅱ](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/)

本题可以买卖多次

dp 数组的含义不变，只不过这里：

```
dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])

dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
```

与上题唯一的不同是，这里可以多次买卖，所以手上是有现金流的，`dp[i-1][1]`的推导中，也不仅是`-prices[i]`，上题只能买卖一次，所以手上是没有现金流的。

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

        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return dp[n - 1][0];
    }
};
```
