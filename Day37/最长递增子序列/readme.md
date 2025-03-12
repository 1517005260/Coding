# 最长递增子序列

例题：[leetcode 300 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/description/)

子序列不需要是连续的。

1. `dp[i]`的定义：

下标 0~i，**以`nums[i]`为结尾的**，最长子序列的长度。

这里的定义一定要包含`nums[i]`，因为只有当 `nums[i]` 大于子序列的最后一个元素时，才能将其添加到该子序列末尾。

如果我们不维护这个信息，只包含下标 0~i 的最长子序列长度，那么对于：

```
[3,1,5,2,7]

到索引2（值为5）时，有子序列 [3,5] 和 [1,5]
```

我们只记录"最长的子序列长度"会丢失这些不同子序列的信息。

2. 递推公式：

对于当前索引下标 i，我们找到所有的 0 ≤ j < i，如果我们发现`nums[i] > nums[j]`，那么我们就可以把`nums[i]`放到`nums[j]`的后面，于是递增子序列长度加一，即`dp[i] = dp[j] + 1`，然后每次更新时取大值即可。

3. 初始化：

`dp[i] = 1`，因为每个元素至少有自己本身这个子序列

4. 遍历顺序：遍历 i 即可

```cpp
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();

        if (n <= 1)
        {
            return n;
        }

        vector<int> dp(n, 1);

        int res = 1; // 递增子序列的长度至少为1
        // 使用res的原因是，dp[i]的定义是以nums[i]结尾的最长递增子序列
        // 而整个数组的最长递增子序列不一定以nums[i]结尾

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};
```
