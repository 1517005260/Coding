# 最长公共子序列

例题：[leetcode 1143 最长公共子序列](https://leetcode.cn/problems/longest-common-subsequence/description/)

本题和[最长重复子数组](../../Day37/最长重复子数组/)的区别就是子数组可以不连续

1. `dp[i][j]`的定义：以`text1[i-1]`，`text2[j-1]`为结尾的最长公共子序列的长度（注意有一位的偏移）

2. 递推公式：

```
text1[i-1] == text2[j-1]，此时只要在之前的长度+1即可，dp[i][j] = dp[i-1][j-1] + 1

text1[i] != text2[j]，此时需要判断

1）text1[i-1]和text2[j-2]
2）text1[i-2]和text2[j-1]

以上两个最长公共子序列的长度谁长即可，dp[i][j] = max(dp[i][j-1], dp[i-1][j])
```

3. 初始化：

```
dp[0][j] = 0，因为不存在下标为-1的地方
dp[i][0] = 0, 因为不存在下标为-1的地方
```

4. 遍历顺序：i，j 依次遍历即可

```cpp
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int res = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // 注意下标，dp[i][j]对应的下标是i-1, j-1
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                res = max(dp[i][j], res);
            }
        }

        return res;
    }
};
```
