# 修剪二叉搜索树

例题：[leetcode 669 修剪二叉搜索树](https://leetcode.cn/problems/trim-a-binary-search-tree/description/)

依据题意，我们需要让树中所有节点落在`[L , R]`的范围内，又根据二叉搜索树的性质：

- 如果当前节点小于 L，那么当前节点的左子树也可以一起抛弃
- 如果当前节点大于 R，那么当前节点的右子树也可以一起抛弃
- 如果当前节点符合条件，那么递归搜索左右子树

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
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (!root)
        {
            return nullptr;
        }

        if (root->val < low)
        {
            return trimBST(root->right, low, high);
        }

        if (root->val > high)
        {
            return trimBST(root->left, low, high);
        }

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};
```
