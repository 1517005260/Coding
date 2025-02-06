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
    bool is_leaf(TreeNode *t)
    {
        return !t->left && !t->right;
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (root)
        {
            q.push(root);
        }
        int res = 0;

        while (!q.empty())
        {
            TreeNode *t = q.front();
            q.pop();

            if (t->left)
            {
                if (is_leaf(t->left))
                {
                    res += t->left->val;
                }
                else
                {
                    q.push(t->left);
                }
            }

            if (t->right && !is_leaf(t->right))
            {
                q.push(t->right);
            }
        }

        return res;
    }
};
// @lc code=end
