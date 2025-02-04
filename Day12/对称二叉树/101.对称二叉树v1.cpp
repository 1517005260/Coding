/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        return compare(root->left, root->right);
    }

    bool compare(TreeNode *left, TreeNode *right)
    {
        // 注意传参含义，这里不是左子树和右子树，而是位置相互对称的左边节点和右边节点

        // 1. 对NULL情况做特殊判断
        if ((!left && right) || (left && !right))
        {
            return false;
        }
        else if (!left && !right)
        {
            // 两个节点都是空的
            return true;
        }
        // 2. 如果两个节点都非空，那么再来判断值是否相等
        else if (left->val != right->val)
        {
            return false;
        }

        // 特殊情况判断完成后再进行递归操作

        // 判断外侧
        bool outsize = compare(left->left, right->right);
        // 判断内侧
        bool inside = compare(left->right, right->left);

        return outsize && inside; // 外侧和内侧同时对称
    }
};
// @lc code=end
