# 买卖股票的最佳时机含手续费

例题：[leetcode 714 买卖股票的最佳时机含手续费](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/)

本题仍然是[Ⅱ](../../Day35/买卖股票的最佳时机%20Ⅱ/)的变式，现在多了手续费，因此只要在买入的时候需要多一次手续费计算即可

1. `dp[i][j]`的定义：

j=0：不持有股票的最大收益
j=1：持有股票的最大收益

2. 递推公式：

```
dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])

dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] - fee)
```

3. 初始化：

```
dp[i][0] = 0
dp[i][1] = -prices[0] - fee
```

4. 遍历顺序：遍历 i 即可

```cpp
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        if (n <= 1)
        {
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = -prices[0] - fee;

        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee);
        }
        return dp[n - 1][0];
    }
};
```
