# 翻转二叉树

例题：[leetcode 226 翻转二叉树](https://leetcode.cn/problems/invert-binary-tree/description/)

思路：不断反转左右节点即可

1. 递归法:

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
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
        {
            return root;
        }

        swap(root->left, root->right); // 进行本节点反转
        invertTree(root->left);        // 开始递归反转左子树和右子树
        invertTree(root->right);
        return root;
    }
};
```

时间复杂度：O(N)，其中 N 为二叉树节点的数目。我们会遍历二叉树中的每一个节点，对每个节点而言，我们在常数时间内交换其两棵子树。

空间复杂度：O(N)。使用的空间由递归栈的深度决定，它等于当前节点在二叉树中的高度。在平均情况下，二叉树的高度与节点个数为对数关系，即 O(logN)。而在最坏情况下，树形成链状，空间复杂度为 O(N)。

2. 层序遍历法：

```cpp
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (root)
        {
            q.push(root);
        }

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                TreeNode *t = q.front();
                q.pop();

                // 反转二叉树
                swap(t->left, t->right);

                if (t->left)
                {
                    q.push(t->left);
                }
                if (t->right)
                {
                    q.push(t->right);
                }
            }
        }

        return root;
    }
};
```
