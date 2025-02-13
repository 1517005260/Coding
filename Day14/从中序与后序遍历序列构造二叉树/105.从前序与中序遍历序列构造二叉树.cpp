/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    unordered_map<int, int> _inorder_map;
    vector<int> _pre;

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            _inorder_map[inorder[i]] = i;
        }

        _pre = preorder;

        TreeNode *t = build(0, preorder.size() - 1, 0, inorder.size() - 1);

        return t;
    }

    TreeNode *build(int preorderStart, int preorderEnd, int inorderStart, int inorderEnd)
    {
        if (preorderStart > preorderEnd || inorderStart > inorderEnd)
        {
            return nullptr;
        }

        // 前序遍历的第一个元素就是本次递归的根元素
        int root = _pre[preorderStart];
        int inorder_root_idx = _inorder_map[root];

        TreeNode *t = new TreeNode(root);

        int left_size = inorder_root_idx - inorderStart;

        t->left = build(preorderStart + 1, preorderStart + left_size, inorderStart, inorder_root_idx - 1);
        t->right = build(preorderStart + left_size + 1, preorderEnd, inorder_root_idx + 1, inorderEnd);

        return t;
    }
};
// @lc code=end
