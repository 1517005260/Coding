# N 皇后

例题：[leetcode 51 N 皇后](https://leetcode.cn/problems/n-queens/description/)

约束条件：

- 不能同行
- 不能同列
- 不能同斜线

枚举过程如下：

![jpg](https://code-thinking-1253855093.file.myqcloud.com/pics/20210130182532303.jpg)

```cpp
class Solution
{
private:
    vector<vector<string>> res;

    // 检查在棋盘上某个位置(row, col)是否可以放置新的皇后
    // 实际坐标右下角是 (n-1,n-1)
    bool is_vaild(int row, int col, vector<string> &chess, int n)
    {
        // 不需要检查水平方向，因为每行只会放置一个皇后
        // 只需要检查当前位置上方的棋盘，因为下方还未放置皇后

        for (int i = 0; i < row; i++)
        {
            // 对于第i行，如果第col列有皇后，则位置不合法
            if (chess[i][col] == 'Q')
            {
                return false;
            }
        }

        // 检查左上方向
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (chess[i][j] == 'Q')
            {
                return false;
            }
        }

        // 检查右上方向
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (chess[i][j] == 'Q')
            {
                return false;
            }
        }

        return true;
    }

    void dfs(vector<string> &chess, int row, int n)
    {
        if (row == n)
        {
            // 枚举到最后一行
            res.push_back(chess);
        }

        for (int col = 0; col < n; col++)
        {
            // 对于固定的行，尝试不同的列
            if (is_vaild(row, col, chess, n))
            {
                chess[row][col] = 'Q';
                dfs(chess, row + 1, n);
                chess[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        // 初始化一个 n * n 的点阵
        vector<string> chess(n, string(n, '.'));
        dfs(chess, 0, n);
        return res;
    }
};
```
