/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1)
        {
            return root2;
        }
        if (!root2)
        {
            return root1;
        }

        TreeNode *t = new TreeNode(root1->val + root2->val);
        t->left = mergeTrees(root1->left, root2->left);
        t->right = mergeTrees(root1->right, root2->right);

        return t;
    }
};
// @lc code=end
