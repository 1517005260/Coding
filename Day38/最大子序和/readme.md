# 最大子序和

例题：[leetcode 53 最大子序和](https://leetcode.cn/problems/maximum-subarray/description/)

子数组必须连续，然后求最大和。

1. `dp[i]` 的定义：以`nums[i]`结尾的最大子数组和

2. 递推公式：

如果和已经小于 0，那么就需要重新开始，这点在[贪心解法](../../Day23/最大子序和/)中提到过。

所以递推公式为：

```
dp[i] = max(dp[i-1] + nums[i], nums[i])
```

**注意`dp[i]`必须包含`nums[i]`**

3. 初始化：

`dp[0] = nums[0]`

4. 遍历顺序：从前向后即可

```cpp
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }

        vector<int> dp(n, 0);
        dp[0] = nums[0];

        // 最大的子序和不一定以nums[n-1]结尾
        int res = dp[0];
        for (int i = 1; i < n; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(res, dp[i]);
        }

        return res;
    }
};
```
