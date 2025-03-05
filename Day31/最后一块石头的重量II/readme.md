# 最后一块石头的重量 II

例题：[leetcode 1049 最后一块石头的重量 II](https://leetcode.cn/problems/last-stone-weight-ii/description/)

和[分割等和子集](../../Day30/分割等和子集/)一样的思路。若我们能将总和为 sum 的 stones 数组，分成尽可能与 sum/2 的接近的两个子数组，那么它们相互粉碎后，剩下的石头重量是最小的。

但通常情况下，我们找不到恰好为 sum/2 的组合，只能尽量接近。所以问题变成：在不超过 sum/2 的前提下，最多能装多少重量的石头

1. `dp[i]`的含义：

- 容量为 i 背包，最大可以背`dp[i]`价值的石头
- 这里，石头 i 的重量是`stones[i]`，价值也是`stones[i]`

2. 递推公式：

对于每个石头，我们可以选择放或者不放：

- 不放入：`dp[j]`保持不变
- 放入：`dp[j] = dp[j - stones[i]] + stones[i]`

两者取大即可

3. 初始化：

一维 01 背包初始化全 0 即可。

4. 遍历顺序：

```
for (石头i)
    for (容量j从target到stones[i]递减)
        dp[j] = max(dp[j], dp[j - stones[i]] + stones[i])
```

5. 最终结果计算

一堆石头的重量为 `dp[sum/2]`，另一堆为`sum - dp[sum/2]`

所以最后剩下的重量就是`(sum - dp[sum/2]) - dp[sum/2]`

```cpp
class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int sum = 0;
        for (int stone : stones)
        {
            sum += stone;
        }

        int target = sum / 2;

        vector<int> dp(target + 1, 0);

        for (int i = 0; i < stones.size(); i++)
        {
            for (int j = target; j >= stones[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return sum - dp[target] - dp[target];
    }
};
```
