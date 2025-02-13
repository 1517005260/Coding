/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    unordered_map<int, int> _inorder_map; // <a[i], i>
    vector<int> _post;                    // 便于参数传递，否则本题的函数传参还需要多写一个post数组，不如改成全局的

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            _inorder_map[inorder[i]] = i;
        }

        _post = postorder;
        TreeNode *t = build(0, inorder.size() - 1, 0, postorder.size() - 1);
        return t;
    }

    TreeNode *build(int inorderStart, int inorderEnd, int postStart, int postEnd)
    {
        if (inorderStart > inorderEnd || postStart > postEnd)
        {
            return nullptr;
        }

        // 取后序遍历中的最后一个元素作为本次递归的根节点
        int root = _post[postEnd];
        // 在中序遍历中找到它
        int inorder_root_idx = _inorder_map[root];

        TreeNode *t = new TreeNode(root);

        int left_size = inorder_root_idx - inorderStart;

        // 进行切割与递归
        t->left = build(inorderStart, inorder_root_idx - 1, postStart, postStart + left_size - 1);
        t->right = build(inorder_root_idx + 1, inorderEnd, postStart + left_size, postEnd - 1);

        return t;
    }
};
// @lc code=end
