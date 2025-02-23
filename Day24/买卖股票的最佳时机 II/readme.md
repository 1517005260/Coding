# 买卖股票的最佳时机 II

例题：[leetcode 122 买卖股票的最佳时机 II](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/)

本题贪心的关键在于：

1. 利润序列比价格序列少一个，因为利润由`price[i] - price[i-1]`构成
2. 我们可以对利润进行分解：

```
若有正利润：prices[3] - prices[0]
我们可以对它进行分解：(prices[3] - prices[2]) + (prices[2] - prices[1]) + (prices[1] - prices[0])
```

于是，我们收集分解出来所有的正利润即可。

```cpp
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int sum = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            sum += max(0, prices[i] - prices[i - 1]);
        }

        return sum;
    }
};
```
