# 二叉搜索树中的搜索

例题：[leetcode 700 二叉搜索树中的搜索](https://leetcode.cn/problems/search-in-a-binary-search-tree/description/)

按照二叉搜索树的定义来搜索即可：

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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (!root)
        {
            return nullptr;
        }

        if (root->val > val)
        {
            return searchBST(root->left, val);
        }
        else if (root->val < val)
        {
            return searchBST(root->right, val);
        }
        else
        {
            return root;
        }
    }
};
```

或者采用迭代法：

```cpp
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (!root)
        {
            return nullptr;
        }

        while (root)
        {
            if (root->val == val)
            {
                return root;
            }
            else if (root->val > val)
            {
                root = root->left;
            }
            else if (root->val < val)
            {
                root = root->right;
            }
        }
        return nullptr;
    }
};
```
