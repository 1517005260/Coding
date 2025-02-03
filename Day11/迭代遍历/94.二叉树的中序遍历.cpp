/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *now = root; // 辅助指针

        while (now != nullptr || !s.empty())
        {
            if (now != nullptr)
            {
                s.push(now);
                now = now->left; // 一路向左
            }
            else
            {
                // now == nullptr
                TreeNode *t = s.top();
                s.pop();
                res.push_back(t->val);
                now = t->right;
            }
        }

        return res;
    }
};
// @lc code=end
