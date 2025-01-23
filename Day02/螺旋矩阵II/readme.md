# 螺旋矩阵 II

例题：[leetcode 59 螺旋矩阵 II](https://leetcode.cn/problems/spiral-matrix-ii/description/)

模拟法：

按照题意蛇形向中间填充。注意边界判断。

```cpp
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int num = 1;                                          // 从 1 开始填充
        int top = 0, bottom = n - 1, left = 0, right = n - 1; // 上下左右边界
        vector<vector<int>> res(n, vector<int>(n, 0));

        while (top <= bottom && left <= right)
        {
            // 首先模拟向右边填充
            for (int i = left; i <= right; i++)
            {
                res[top][i] = num++;
            }
            top++;

            // 接着模拟向下填充
            for (int i = top; i <= bottom; i++)
            {
                res[i][right] = num++;
            }
            right--;

            // 接着模拟向左填充
            for (int i = right; i >= left; i--)
            {
                res[bottom][i] = num++;
            }
            bottom--;

            // 最后模拟向上填充
            for (int i = bottom; i >= top; i--)
            {
                res[i][left] = num++;
            }
            left++;
        }

        return res;
    }
};
```
