/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    int res = 0;
    int max_depth = INT_MIN;

public:
    int findBottomLeftValue(TreeNode *root)
    {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode *t, int depth)
    {
        if (!t->left && !t->right)
        {
            // 抵达叶子节点
            if (depth > max_depth)
            {
                // 只会在第一次抵达最深层时更新，所以一定是最左边的
                max_depth = depth;
                res = t->val;
            }
        }

        if (t->left)
        {
            dfs(t->left, depth + 1);
        }

        if (t->right)
        {
            dfs(t->right, depth + 1);
        }
    }
};
// @lc code=end
