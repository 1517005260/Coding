/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        order(root, res, 0);
        return res;
    }

    void order(TreeNode *t, vector<vector<int>> &res, int depth)
    {
        if (!t)
        {
            return;
        }

        if (res.size() == depth)
        {
            res.push_back(vector<int>()); // 需要新的一层
        }

        res[depth].push_back(t->val);
        order(t->left, res, depth + 1);
        order(t->right, res, depth + 1);
    }
};
// @lc code=end
