/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (root)
        {
            q.push(root);
        }

        int depth = 0;
        while (!q.empty())
        {
            int size = q.size();
            depth++;

            while (size--)
            {
                TreeNode *t = q.front();
                q.pop();

                if (!t->left && !t->right)
                {
                    return depth;
                }
                if (t->left)
                {
                    q.push(t->left);
                }
                if (t->right)
                {
                    q.push(t->right);
                }
            }
        }

        return depth;
    }
};
// @lc code=end
