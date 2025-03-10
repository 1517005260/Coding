# 买卖股票的最佳时机 Ⅲ

例题：[leetcode 123 买卖股票的最佳时机 Ⅲ](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/)

本题至多可以买卖两次，所以一共有如下的状态：

- 不买卖
- 买卖一次
- 买卖两次

## 1. 状态定义

我们使用二维数组 `dp[i][j]` 来表示动态规划的状态：

- `i` 表示交易进行到第 i 天
- `j` 表示当前处于哪种交易状态

对于最多允许两次交易的情况，我们可以定义 5 种状态（j 的取值为 0 到 4）：

- `j=0`: 未进行任何操作
- `j=1`: 完成第一次买入
- `j=2`: 完成第一次卖出（完成第一笔交易）
- `j=3`: 完成第二次买入
- `j=4`: 完成第二次卖出（完成第二笔交易）

## 2. 状态转移方程

在每一天，我们都要考虑从前一天的各个状态转移而来：

1. **未进行任何操作**：

   ```cpp
   dp[i][0] = 0;
   ```

   这个状态很简单，如果不进行任何操作，利润始终为 0。

2. **第一次买入**：

   ```cpp
   dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
   ```

   这里有两种可能：

   - 维持前一天已经买入的状态：`dp[i-1][1]`
   - 今天第一次买入：`dp[i-1][0] - prices[i]`（从未操作状态转入，减去今天的股票价格）

3. **第一次卖出**：

   ```cpp
   dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
   ```

   这里也有两种可能：

   - 维持前一天已经卖出的状态：`dp[i-1][2]`
   - 今天卖出第一次买入的股票：`dp[i-1][1] + prices[i]`（从第一次买入状态转入，加上今天的股票价格）

4. **第二次买入**：

   ```cpp
   dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);
   ```

   同样有两种可能：

   - 维持前一天已经第二次买入的状态：`dp[i-1][3]`
   - 今天进行第二次买入：`dp[i-1][2] - prices[i]`（从第一次卖出状态转入，减去今天的股票价格）

5. **第二次卖出**：
   ```cpp
   dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);
   ```
   两种可能：
   - 维持前一天已经第二次卖出的状态：`dp[i-1][4]`
   - 今天卖出第二次买入的股票：`dp[i-1][3] + prices[i]`（从第二次买入状态转入，加上今天的股票价格）

## 3. 初始化

```cpp
dp[0][0] = 0;            // 未进行任何操作
dp[0][1] = -prices[0];   // 第一次买入
dp[0][2] = 0;            // 第一次卖出（不可能，因此为0）
dp[0][3] = -prices[0];   // 第二次买入（不可能，设置为-prices[0]保持一致性）
dp[0][4] = 0;            // 第二次卖出（不可能，因此为0）
```

注意：

- 第一天进行第一次买入，利润为负的股票价格
- 第一天不可能完成卖出操作，所以相关状态初始化为 0
- 第一天进行第二次买入在逻辑上是不可能的（因为没有第一次卖出），但为了保持状态转移的一致性，我们也将其初始化为 `-prices[0]`

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

        vector<vector<int>> dp(n, vector<int>(5, 0));

        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        dp[0][3] = -prices[0];
        dp[0][4] = 0;

        for (int i = 1; i < n; i++)
        {
            // 不操作
            dp[i][0] = 0;

            // 第一次买入
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);

            // 第一次卖出
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);

            // 第二次买入
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);

            // 第二次卖出
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }

        return max(dp[n - 1][0], max(dp[n - 1][2], dp[n - 1][4]));
    }
};
```
