# 完全二叉树的节点个数

例题：[leetcode 222 完全二叉树的节点个数](https://leetcode.cn/problems/count-complete-tree-nodes/description/)

## 按照普通二叉树的解法

1. 递归法

递归统计左右子树的节点个数即可。

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
    int countNodes(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```

时间复杂度：O(n)，空间复杂度：O(log n)，算上了递归系统栈占用的空间

2. 层序遍历法

在遍历的模板上加上统计个数即可：

```cpp
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (root)
        {
            q.push(root);
        }
        int cnt = 0;

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                cnt++;
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
        return cnt;
    }
};
```

时间复杂度：O(n)，空间复杂度：O(n)

## 按照完全二叉树的做法

首先，来看什么是完全二叉树：

![png](https://code-thinking-1253855093.file.myqcloud.com/pics/20200920221638903-20230310123444151.png)

完全二叉树只有两种情况，情况一：就是满二叉树，情况二：最后一层叶子节点没有满。

对于情况一，可以直接用 `2^树深度 - 1` 来计算，注意这里根节点深度为 1。

对于情况二，分别递归左孩子，和右孩子，递归到某一深度一定会有左孩子或者右孩子为满二叉树（如下图），然后依然可以按照情况 1 来计算。

![png](https://code-thinking-1253855093.file.myqcloud.com/pics/20201124092543662.png)

可以看出如果整个树不是满二叉树，就递归其左右孩子，直到遇到满二叉树为止，用公式计算这个子树（满二叉树）的节点数量。

这里关键在于如何去判断一个左子树或者右子树是不是满二叉树呢？

在完全二叉树中，如果递归向左遍历的深度等于递归向右遍历的深度，那说明就是满二叉树。如图：

![png](https://code-thinking-1253855093.file.myqcloud.com/pics/20220829163554.png)

如下则不是满二叉树：

![png](https://code-thinking-1253855093.file.myqcloud.com/pics/20220829163709.png)

需要注意的是如下**不是完全二叉树**：

![png](https://code-thinking-1253855093.file.myqcloud.com/pics/20220829163811.png)

```cpp
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        TreeNode *left = root->left;
        TreeNode *right = root->right;

        int left_depth = 0;
        int right_depth = 0;

        while (left)
        {
            left_depth++;
            left = left->left;
        }

        while (right)
        {
            right_depth++;
            right = right->right;
        }

        if (left_depth == right_depth)
        {
            return (2 << left_depth) - 1; // (2^left_depth)-1
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```

时间复杂度：O(log n × log n)，空间复杂度：O(log n)
