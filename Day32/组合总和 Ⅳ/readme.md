# 组合总和 Ⅳ

例题：[leetcode 377 组合总和 Ⅳ](https://leetcode.cn/problems/combination-sum-iv/description/)

请注意，顺序不同的序列被视作不同的组合。 => 所以，本题本质上在求排列。

本题可以看作[爬楼梯](../../Day28/爬楼梯/)。这里，需要爬到 target 楼，你可以从 nums 中选择当前爬的层数。并且先上 3 层再上 1 层和先上 1 层再上 3 层的策略是不同的。

1. `dp[i]`的含义：总和为 i，一共有`dp[i]`种排列方式

2. 递推公式：

由爬楼梯的公式：`dp[i] = dp[i-1] + dp[i-2]`，到每层楼梯的方法可以由前一阶和前两阶递推出来。即：最后一次爬一层 or 两层。

这里是类似的，到每层楼梯的方法可以由前 j 阶推出来，即：`dp[i] += dp[i - nums[j]]`。即：最后一次爬`nums[j]`层

3. 初始化：

`dp[0]=1`，即我们已经在第 0 层了。

4. 遍历顺序：内层遍历`nums[j]`，外层更新`dp[i]`

```cpp
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        // 本题有用int会溢出的数据
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++)
        {
            for (int n : nums)
            {
                if (i >= n)
                {
                    // n = nums[j]
                    dp[i] += dp[i - n];
                }
            }
        }

        return dp[target];
    }
};
```
