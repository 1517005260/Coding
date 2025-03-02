# 不同路径 II

例题：[leetcode 63 不同路径 II](https://leetcode.cn/problems/unique-paths-ii/description/)

1. 同[上题](../不同路径/)，`dp[i][j]`表示到(i,j)的不同路径数量

2. 递推公式：

由于本题新增了障碍物，所以若(i,j)为障碍物，`dp[i][j]=0`，其他不变

3. 初始化

由于本题新增了障碍物，所以向右或向下最多只能走到障碍物的位置

4. 遍历顺序

逐层遍历

```cpp
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // 初始化
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++)
        {
            // 如果碰到障碍物，后续的dp均为0
            dp[0][j] = 1;
        }

        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
```
