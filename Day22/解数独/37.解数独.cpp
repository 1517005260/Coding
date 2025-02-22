/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution
{
    bool is_valid(int row, int col, char val, vector<vector<char>> &board)
    {
        // 1. 行内不重复
        for (int j = 0; j < 9; j++)
        {
            if (board[row][j] == val)
            {
                return false;
            }
        }

        // 2. 列内不重复
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == val)
            {
                return false;
            }
        }

        // 3. 所处的小九宫格内不重复
        // 先获取所在九宫格的起始位置，利用下取整的特性
        int x = (row / 3) * 3;
        int y = (col / 3) * 3;
        for (int i = x; i < x + 3; i++)
        {
            for (int j = y; j < y + 3; j++)
            {
                if (board[i][j] == val)
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool dfs(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    // 找到空位，尝试放数字
                    for (char num = '1'; num <= '9'; num++)
                    {
                        if (is_valid(i, j, num, board))
                        {
                            board[i][j] = num;
                            if (dfs(board))
                            {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }

                    // 9个数都试过了，都不符合
                    return false;
                }
            }
        }

        // 遍历完无false说明找到解了
        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        dfs(board);
    }
};
// @lc code=end
