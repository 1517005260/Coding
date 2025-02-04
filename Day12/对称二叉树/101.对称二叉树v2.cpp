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

        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty())
        {
            TreeNode *l = q.front();
            q.pop();
            TreeNode *r = q.front();
            q.pop();

            // 如果两个都空，那么就继续，本层判断为true
            if (!l && !r)
            {
                continue;
            }

            // 其他判断和递归法一致
            if ((!l && r) || (l && !r) || (l->val != r->val))
            {
                return false;
            }

            // 放入外侧子节点
            q.push(l->left);
            q.push(r->right);

            // 放入内侧子节点
            q.push(l->right);
            q.push(r->left);
        }
        return root;
    }
};
// @lc code=end
