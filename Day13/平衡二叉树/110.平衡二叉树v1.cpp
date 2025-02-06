/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }

        return isBalanced(root->left) && isBalanced(root->right) && abs(get_height(root->left) - get_height(root->right)) <= 1;
    }

    int get_height(TreeNode *t)
    {
        if (!t)
        {
            return 0;
        }
        return 1 + max(get_height(t->left), get_height(t->right));
    }
};
// @lc code=end
