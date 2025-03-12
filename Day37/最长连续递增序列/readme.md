# 最长连续递增序列

例题：[leetcode 674 最长连续递增序列](https://leetcode.cn/problems/longest-continuous-increasing-subsequence/description/)

本题的子数组必须递增，所以相比[上题](../最长递增子序列/)，本题的 j 就是 i-1

```cpp
class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
        {
            return n;
        }

        vector<int> dp(n, 1);

        int res = 1;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                dp[i] = max(dp[i], dp[i - 1] + 1);
            }

            res = max(dp[i], res);
        }

        return res;
    }
};
```
