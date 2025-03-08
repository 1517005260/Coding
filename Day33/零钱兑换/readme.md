# 零钱兑换

例题：[leetcode 322 零钱兑换](https://leetcode.cn/problems/coin-change/description/)

本题也可以看作爬楼梯的变式。目标阶层是 amount，你可以在 coins 中选择爬几层，可以无限选同一层，要求次数最少。

1. `dp[i]`的含义：爬上第 i 层的最小步数是`dp[i]` => 凑足总额为 i 所需钱币的最少个数为`dp[i]`

2. 递推公式

仍然是遍历`conis[j]`，由于是最小步数，所以：

```
dp[i] = min(dp[i], dp[i - coins[j]] + 1)
```

这里，` dp[i - coins[j]] + 1`代表选`coins[j]`，只要多一步就能凑成 i

3. 初始化：由于需要取 min，所以 dp 数组需要初始化成较大值

此外，`dp[0] = 0`，因为凑成 0 的方法为 0 种

4. 遍历顺序：先遍历 i 后遍历 j

```cpp
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 100); // 初始化成较大值
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            for (int coin : coins)
            {
                if (i >= coin)
                {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // 如果dp[amount]仍然是amount+100，说明没有能组成它的方法
        if (dp[amount] == amount + 100)
        {
            return -1;
        }
        return dp[amount];
    }
};
```
