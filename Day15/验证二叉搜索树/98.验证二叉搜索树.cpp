/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    vector<int> _vec; // 中序遍历结果
    void build(TreeNode *t)
    {
        if (!t)
        {
            return;
        }

        build(t->left);
        _vec.push_back(t->val);
        build(t->right);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        _vec.clear();
        build(root);
        for (int i = 1; i < _vec.size(); i++)
        {
            if (_vec[i] <= _vec[i - 1])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
