# 一和零

例题：[leetcode 474 一和零](https://leetcode.cn/problems/ones-and-zeroes/description/)

1. `dp[i][j]`的含义：最多有 i 个 0 和 j 个 1 的最大子集长度为`dp[i][j]`

**注意**：这里仍然是一维 dp，只不过这里一维数组不能表是所有状态，所以用的是二维数组。

2. 递推公式

对于每个字符串 str，假设它包含 zeros 个 '0' 和 ones 个 '1'，我们有两个选择：

- 不选择这个字符串：`dp[i][j]`，保持不变
- 选择这个字符串：`dp[i][j] = dp[i-zeros][j-ones] + 1`（前提是 i >= zeros 且 j >= ones）

我们取这两种选择的最大值：`dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones] + 1)`

3. 初始化

初始时 `dp[i][j] = 0`，表示一个字符串都不选择。

4. 先顺序遍历物品（字符串），然后逆序遍历容量（0，1）

```cpp
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (string str : strs)
        {
            int zeros = 0, ones = 0;

            for (char c : str)
            {
                if (c == '1')
                {
                    ones++;
                }
                else
                {
                    zeros++;
                }
            }

            for (int i = m; i >= zeros; i--)
            {
                for (int j = n; j >= ones; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
```
