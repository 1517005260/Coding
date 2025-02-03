/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode *root)
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
            if (t->right) // 注意需要非空判断，否则会push到null
                s.push(t->right);
            if (t->left)
                s.push(t->left);
        }

        return res;
    }
};
// @lc code=end
