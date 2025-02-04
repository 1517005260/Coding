# 对称二叉树

例题：[leetcode 101 对称二叉树](https://leetcode.cn/problems/symmetric-tree/description/)

![png](https://code-thinking-1253855093.file.myqcloud.com/pics/20210203144624414.png)

如图，需要比较的是外侧和里侧的子树，而不是左右子树。

1. 递归法

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
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        return compare(root->left, root->right);
    }

    bool compare(TreeNode *left, TreeNode *right)
    {
        // 注意传参含义，这里不是左子树和右子树，而是位置相互对称的左边节点和右边节点

        // 1. 对NULL情况做特殊判断
        if ((!left && right) || (left && !right))
        {
            return false;
        }
        else if (!left && !right)
        {
            // 两个节点都是空的
            return true;
        }
        // 2. 如果两个节点都非空，那么再来判断值是否相等
        else if (left->val != right->val)
        {
            return false;
        }

        // 特殊情况判断完成后再进行递归操作

        // 判断外侧
        bool outsize = compare(left->left, right->right);
        // 判断内侧
        bool inside = compare(left->right, right->left);

        return outsize && inside; // 外侧和内侧同时对称
    }
};
```

2. 层序遍历法：

原理如动画所示：

![gif](https://code-thinking.cdn.bcebos.com/gifs/101.%E5%AF%B9%E7%A7%B0%E4%BA%8C%E5%8F%89%E6%A0%91.gif)

```cpp
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }

        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty())
        {
            TreeNode *l = q.front();
            q.pop();
            TreeNode *r = q.front();
            q.pop();

            // 如果两个都空，那么就继续，本层判断为true
            if (!l && !r)
            {
                continue;
            }

            // 其他判断和递归法一致
            if ((!l && r) || (l && !r) || (l->val != r->val))
            {
                return false;
            }

            // 放入外侧子节点
            q.push(l->left);
            q.push(r->right);

            // 放入内侧子节点
            q.push(l->right);
            q.push(r->left);
        }
        return root;
    }
};
```

# 相关题目

1. [leetcode 100 相同的树](https://leetcode.cn/problems/same-tree/description/)
2. [leetcode 572 另一棵树的子树](https://leetcode.cn/problems/subtree-of-another-tree/description/)
