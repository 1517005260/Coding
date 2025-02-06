/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;

        queue<TreeNode *> node;
        queue<string> path;

        if (root)
        {
            node.push(root);
            path.push(to_string(root->val));
        }

        while (!node.empty())
        {
            TreeNode *t = node.front();
            node.pop();
            string p = path.front();
            path.pop();

            if (!t->left && !t->right)
            {
                res.push_back(p);
            }
            else
            {
                if (t->left)
                {
                    node.push(t->left);
                    path.push(p + "->" + to_string(t->left->val));
                }

                if (t->right)
                {
                    node.push(t->right);
                    path.push(p + "->" + to_string(t->right->val));
                }
            }
        }

        return res;
    }
};
// @lc code=end
