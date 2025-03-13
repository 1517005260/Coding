# 不相交的线

例题：[leetcode 1035 不相交的线](https://leetcode.cn/problems/uncrossed-lines/description/)

直线不能相交，这就是说明在字符串 nums1 中 找到一个与字符串 nums2 相同的子序列，且这个子序列不能改变相对顺序，只要相对顺序不改变，连接相同数字的直线就不会相交。

本题就是[最长公共子序列](../最长公共子序列/)，且相对顺序不能变。

```cpp
class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int res = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
                res = max(res, dp[i][j]);
            }
        }

        return res;
    }
};
```
