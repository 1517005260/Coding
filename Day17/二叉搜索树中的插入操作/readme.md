# 二叉搜索树中的插入操作

例题：[leetcode 701 二叉搜索树中的插入操作](https://leetcode.cn/problems/insert-into-a-binary-search-tree/description/)

进行遍历，缝空插入即可：

```cpp
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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *t = new TreeNode(val);
        if (!root)
        {
            // 缝空插入
            return t;
        }

        if (root->val > val)
        {
            root->left = insertIntoBST(root->left, val);
        }
        else
        {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};
```
