# 二叉树的最大深度

例题：[leetcode 104 二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/)

1. 递归法

对左子树和右子树递归统计即可。

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
    int maxDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right)); // 本层不空，递归计算下层
    }
};
```

2. 层序遍历法

层序遍历时统计深度即可

```cpp
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        queue<TreeNode *> q;

        if (root)
        {
            q.push(root);
        }

        int depth = 0;
        while (!q.empty())
        {
            int size = q.size();
            depth++;

            while (size--)
            {
                TreeNode *t = q.front();
                q.pop();

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
        return depth;
    }
};
```

## 相关题目

[leetcode 559 N 叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-n-ary-tree/description/)
