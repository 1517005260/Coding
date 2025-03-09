# 打家劫舍

例题：[leetcode 198 打家劫舍](https://leetcode.cn/problems/house-robber/description/)

本题的关键在于：**当前房屋偷与不偷取决于前一个房屋和前两个房屋是否被偷了**

1. `dp[i]` 代表：前 i 个房间，可以偷盗的最大金额

2. 递推公式：

```
如果我们要偷i，那么只能先偷前面的i-2，即dp[i] = dp[i-2] + nums[i]

如果我们不偷i，那么金额数和dp[i-1]持平
```

综上，`dp[i] = max(dp[i-1], dp[i-2] + nums[i])`

即：

- 如果偷，就要放弃上一个房屋，但可以得到当前房屋的金额
- 如果不偷，就保持之前的收益不变

每次决策都基于之前的最优结果，然后得到当前的最优结果。

3. 初始化

由递推公式可知，我们需要初始化`dp[0], dp[1]`，这里：

```
dp[0] = nums[0]
dp[1] = max(dp[0], dp[1]) // 可以选择不偷0，去偷1
```

4. 遍历顺序：从前向后遍历

```cpp
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return nums[0];
        }

        vector<int> dp(n, 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[n - 1];
    }
};
```
