/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
        {
            return res;
        }

        stack<TreeNode *> s;
        s.push(root);

        while (!s.empty())
        {
            TreeNode *t = s.top();
            s.pop();
            res.push_back(t->val);

            if (t->left)
            {
                s.push(t->left);
            }
            if (t->right)
            {
                s.push(t->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
