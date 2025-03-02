# 不同路径

例题：[leetcode 62 不同路径](https://leetcode.cn/problems/unique-paths/description/)

1. `dp[i][j]`的含义：到(i, j)的不同路径数

2. 递推公式：

```
(i,j)只能由上面或者左边而来

所以有：dp[i][j] = dp[i-1][j] + dp[i][j-1]
```

3. 初始化：

由于不能向上或向左，所以第一行的 dp 均为 1，第一列的 dp 也都为 1

4. 遍历顺序：一行一行遍历即可

```cpp
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // 初始化
        for (int j = 0; j < n; j++)
        {
            dp[0][j] = 1;
        }
        for (int i = 0; i < m; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};
```
