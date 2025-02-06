/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool _res = true;

public:
    bool isBalanced(TreeNode *root)
    {
        int height = helper(root);
        return _res;
    }

    int helper(TreeNode *t)
    {
        if (!t)
        {
            return 0;
        }

        int left_height = 1 + helper(t->left);
        int right_height = 1 + helper(t->right);

        if (abs(left_height - right_height) > 1)
        {
            _res = false;
        }

        // 返回子树高度
        return max(left_height, right_height);
    }
};
// @lc code=end
