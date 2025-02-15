/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
        {
            return nullptr;
        }

        // 首先，我们需要找到需要删除的节点
        if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            // 找到了要删掉的节点
            // 情况1
            if (!root->left)
            {
                return root->right;
            }

            // 情况2
            if (!root->right)
            {
                return root->left;
            }

            // 情况3
            // 首先需要找到右子树的最小值
            TreeNode *now = root->right;
            TreeNode *pre = root;

            bool flag = false; // 是否进入while循环

            while (now->left)
            {
                flag = true;
                pre = now;
                now = now->left;
            }

            // 现在now的左子树为空，now就是右子树的最左边的节点，即最小值
            // 只要删除now，now顶替root即可
            root->val = now->val;

            if (flag)
            {
                pre->left = now->right;
            }
            else
            {
                pre->right = now->right;
            }
        }
        return root;
    }
};
// @lc code=end
