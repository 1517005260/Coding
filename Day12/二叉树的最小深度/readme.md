# 二叉树的最小深度

例题：[leetcode 111 二叉树的最小深度](https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/)

注意这里最小深度的定义：

![png](https://code-thinking.cdn.bcebos.com/pics/111.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E5%B0%8F%E6%B7%B1%E5%BA%A6.png)

1. 层序遍历法和最大深度法思路一致，只要在左右儿子均为 null 的情况下 break 即可

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
    int minDepth(TreeNode *root)
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

                if (!t->left && !t->right)
                {
                    return depth;
                }
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

2. 递归法

如果直接写：

```cpp
int leftDepth = getDepth(node->left);
int rightDepth = getDepth(node->right);
int result = 1 + min(leftDepth, rightDepth);
return result;
```

那么就犯了图中的错误，如果这么求的话，没有左孩子的分支会算为最短深度。

所以，应该为：如果左子树为空，右子树不为空，说明最小深度是 1 + 右子树的深度。

反之，右子树为空，左子树不为空，最小深度是 1 + 左子树的深度。 最后如果左右子树都不为空，返回左右子树深度最小值 + 1 。

```cpp
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int left_depth = minDepth(root->left);
        int right_depth = minDepth(root->right);

        if (!root->left && root->right)
        {
            return 1 + right_depth;
        }
        if (root->left && !root->right)
        {
            return 1 + left_depth;
        }
        return 1 + min(left_depth, right_depth);
    }
};
```
