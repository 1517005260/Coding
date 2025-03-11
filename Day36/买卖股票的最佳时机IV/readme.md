# 买卖股票的最佳时机 IV

例题：[leetcode 188 买卖股票的最佳时机 IV](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/description/)

本题和[Ⅲ](../../Day35/买卖股票的最佳时机%20Ⅲ/)差不多，只不过买卖的次数可以自定义了。

1. `dp[i][j]`的定义：第 i 天的 j 个状态：

```
j = 0 表示什么都不操作
j = 1 表示第一次买入
j = 2 表示第一次卖出
j = 3 表示第二次买入
j = 4 表示第二次卖出
......
```

显然，当 j 是奇数的时候买入，j 是偶数的时候卖出，一共可以有 k 次交易，所以 j 可以取到 2k

2. 递推公式：

我们开个循环，j+=2 即可

```
j是奇数，即买入状态：要么是当天买入，要么是维持买入状态
dp[i][j] = max(dp[i-1][j-1] - prices[i], dp[i-1][j])

j是偶数，即卖出状态，要么是当天卖出，要么是保持卖出状态
dp[i][j] = max(dp[i-1][j-1] + prices[i], dp[i-1][j])
```

3. 初始化：

```
dp[0][0] = 0;
dp[0][1] = -prices[0];
dp[0][2] = 0;
dp[0][3] = -prices[0];
....
```

理由同[Ⅲ](../../Day35/买卖股票的最佳时机%20Ⅲ/)

4. 遍历顺序：遍历 i 即可

```cpp
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1)
        {
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(2 * k + 1, 0));

        // 初始化
        for (int j = 1; j <= 2 * k; j += 2)
        {
            dp[0][j] = -prices[0];
        }

        // 遍历
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= 2 * k - 2; j += 2)
            {
                // 买入
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);

                // 卖出
                dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
            }
        }

        return dp[n - 1][2 * k];
    }
};
```
