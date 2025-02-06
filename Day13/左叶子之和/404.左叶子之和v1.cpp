/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        return dfs(root);
    }

    bool is_leaf(TreeNode *t)
    {
        return !t->left && !t->right;
    }

    int dfs(TreeNode *t)
    {
        int res = 0;
        if (t->left)
        {
            // t还有左节点
            // 1. 左叶子 2. 左树
            if (is_leaf(t->left))
            {
                res += t->left->val;
            }
            else
            {
                res += dfs(t->left);
            }
        }

        if (t->right && !is_leaf(t->right))
        {
            res += dfs(t->right);
        }
        return res;
    }
};
// @lc code=end
