/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
        TreeNode *ancestor = root;

        // 由于本树是有序的
        // 所以，我们只需要找到分叉点即可
        while (true)
        {
            if (ancestor->val > p->val && ancestor->val > q->val)
            {
                ancestor = ancestor->left;
            }
            else if (ancestor->val < p->val && ancestor->val < q->val)
            {
                ancestor = ancestor->right;
            }
            else
            {
                // 分叉点，例如 p < ancestor < q
                break;
            }
        }

        return ancestor;
    }
};
// @lc code=end
