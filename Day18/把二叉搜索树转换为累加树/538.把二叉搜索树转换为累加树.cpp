/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
private:
    int _pre = 0; // 记录前一个节点的值，用于累加
    void dfs(TreeNode *t)
    {
        if (!t)
        {
            return;
        }

        dfs(t->right);

        t->val += _pre;
        _pre = t->val;

        dfs(t->left);
    }

public:
    TreeNode *convertBST(TreeNode *root)
    {
        dfs(root);
        return root;
    }
};
// @lc code=end
