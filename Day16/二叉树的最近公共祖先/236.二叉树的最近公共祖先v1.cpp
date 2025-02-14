/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // p或q为root时，最近祖先就是root
        if (!root || p == root || q == root)
        {
            return root;
        }

        // 左右中
        // 分别在左右子树中寻找p和q
        // 返回值可能是：p、q、它们的公共祖先、或NULL
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
        {
            // 如果左右子树都返回非空值，说明p和q分别在当前节点的左右子树中。这种情况下，当前节点就是最近公共祖先
            return root;
        }

        // 如果只有一边子树返回非空值，说明p和q都在这边子树中，把这边子树的结果向上传递
        if (!left && right)
        {
            return right;
        }

        if (left && !right)
        {
            return left;
        }

        // !left && !right
        return nullptr;
    }
};
// @lc code=end
