# 最长重复子数组

例题：[leetcode 718 最长重复子数组](https://leetcode.cn/problems/maximum-length-of-repeated-subarray/description/)

注：本题的子数组是连续的

1. `dp[i][j]`的定义：nums1 的下标 i 和 nums2 的下标 j，他们的最长重复子数组为`dp[i][j]`

2. 递推公式：

```
如果nums[i] == nums[j]， 那么就可以尝试扩展重复子数组的长度
即：dp[i][j] = dp[i-1][j-1] + 1

否则，dp[i][j]保持为0
```

3. 初始化：

单独初始化第 0 行和第 0 列即可

4. 遍历顺序：双重 i，j 循环

```cpp
class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        int res = 0;

        // 初始化，判断单个元素相等的情况
        for (int j = 0; j < n; j++)
        {
            if (nums1[0] == nums2[j])
            {
                dp[0][j] = 1;
                res = 1;
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (nums1[i] == nums2[0])
            {
                dp[i][0] = 1;
                res = 1;
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }

        return res;
    }
};
```
