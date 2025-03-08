# 完全平方数

例题：[leetcode 279 完全平方数](https://leetcode.cn/problems/perfect-squares/description/)

还是爬楼梯的变式，和[零钱兑换](../零钱兑换/)差不多，只不过现在你手中可用的变成了所有完全平方数

1. `dp[i]`表示整数 i 最少需要`dp[i]`个完全平方数组成

2. 递推公式：同零钱兑换的思路

```
dp[i] = min(dp[i], dp[i - j*j] + 1)
```

3. 初始化：还是求最小值，所以初始化为较大值

`dp[0] = 0`，因为 0 无法凑出

4. 遍历顺序：先 i 后 j 即可

```cpp
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};
```
