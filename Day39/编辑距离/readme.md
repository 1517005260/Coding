# 编辑距离

例题：[leetcode 72 编辑距离](https://leetcode.cn/problems/edit-distance/description/)

## 问题理解

编辑距离是指将一个字符串转换成另一个字符串所需的最少操作次数。可以执行的操作有：

1. 插入一个字符
2. 删除一个字符
3. 替换一个字符

例如，将"horse"转换为"ros"的编辑距离是 3，需要经过以下操作：

- 将'h'替换为'r'：horse → rorse
- 删除第二个'r'：rorse → rose
- 删除'e'：rose → ros

## 动态规划解法

### 1. 定义状态

首先我们定义状态`dp[i][j]`表示：将`word1`的前`i`个字符（`word1[i-1]`）转换为`word2`的前`j`个字符（`word2[j-1]`）所需的最少操作次数。

### 2. 确定状态转移方程

当我们考虑`dp[i][j]`时，有以下几种情况：

```
if (word1[i - 1] == word2[j - 1])
    不操作
if (word1[i - 1] != word2[j - 1])
    增
    删
    换
```

- 若`word1[i-1] == word2[j-1]`，说明这两个字符相同，不需要任何操作：

  ```
  dp[i][j] = dp[i-1][j-1]
  ```

- 若`word1[i-1] != word2[j-1]`，那么我们需要执行一次操作，有三种选择：

  1. **替换**：将`word1[i-1]`替换为`word2[j-1]`，此时：

     ```
     dp[i][j] = dp[i-1][j-1] + 1
     ```

  2. **删除**：word1 删除一个元素，那么就是以下标 i - 2 为结尾的 word1 与 j-1 为结尾的 word2 的最近编辑距离 再加上一个操作。

     ```
     dp[i][j] = dp[i-1][j] + 1
     ```

  3. **插入**：word2 删除一个元素，那么就是以下标 i - 1 为结尾的 word1 与 j-2 为结尾的 word2 的最近编辑距离 再加上一个操作。word2 添加一个元素，相当于 word1 删除一个元素。

     ```
     dp[i][j] = dp[i][j-1] + 1
     ```

在这三种操作中，我们选择操作次数最少的那个：

```
dp[i][j] = min(dp[i-1][j-1] + 1, dp[i-1][j] + 1, dp[i][j-1] + 1)
```

### 3. 初始化 DP 数组

- `dp[i][0]`表示将`word1`的前`i`个字符转换为空字符串所需的操作次数，显然需要删除`i`个字符，所以`dp[i][0] = i`。
- `dp[0][j]`表示将空字符串转换为`word2`的前`j`个字符所需的操作次数，显然需要插入`j`个字符，所以`dp[0][j] = j`。

### 4. 计算顺序

由于状态转移方程依赖于左上、上方和左方的状态，所以我们需要从左到右、从上到下进行计算。

## 例子推导

以"horse"和"ros"为例，DP 表格填充过程如下：

|     |     | r   | o   | s   |
| --- | --- | --- | --- | --- |
|     | 0   | 1   | 2   | 3   |
| h   | 1   | 1   | 2   | 3   |
| o   | 2   | 2   | 1   | 2   |
| r   | 3   | 2   | 2   | 2   |
| s   | 4   | 3   | 3   | 2   |
| e   | 5   | 4   | 4   | 3   |

最终的编辑距离是 3，即`dp[5][3] = 3`。

```cpp
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // 初始化
        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++)
        {
            dp[0][j] = j;
        }

        // dp
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    // 需要进行增删改的操作
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                }
            }
        }
        return dp[m][n];
    }
};
```
