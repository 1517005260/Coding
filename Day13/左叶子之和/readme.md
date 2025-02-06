# 左叶子之和

例题：[leetcode 404 左叶子之和](https://leetcode.cn/problems/sum-of-left-leaves/description/)

首先，什么是左叶子？节点 A 的左孩子不为空，且左孩子的左右孩子都为空（说明是叶子节点），那么 A 节点的左孩子为左叶子节点。

如图：

![png](https://code-thinking-1253855093.file.myqcloud.com/pics/20210204151949672.png)

本树没有左叶子

如图：

![png](https://code-thinking-1253855093.file.myqcloud.com/pics/20220902165805.png)

左叶子之和为 21

1. dfs

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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        return dfs(root);
    }

    bool is_leaf(TreeNode *t)
    {
        return !t->left && !t->right;
    }

    int dfs(TreeNode *t)
    {
        int res = 0;
        if (t->left)
        {
            // t还有左节点
            // 1. 左叶子 2. 左树
            if (is_leaf(t->left))
            {
                res += t->left->val;
            }
            else
            {
                res += dfs(t->left);
            }
        }

        if (t->right && !is_leaf(t->right))
        {
            res += dfs(t->right);
        }
        return res;
    }
};
```

模拟一下，假设我们有这样一棵二叉树：

```
    3
   / \
  9  20
     /  \
    15   7
```

在这棵树中：

- 9 是一个左叶子节点（它是 3 的左子节点，并且自己没有子节点）
- 15 是一个左叶子节点（它是 20 的左子节点，并且自己没有子节点）
- 7 是一个右叶子节点（不计入和）

所以这棵树的左叶子之和应该是：9 + 15 = 24

让我们看看代码是如何工作的：

- 首先，`sumOfLeftLeaves`函数是入口，它检查树是否为空，不为空就调用`dfs`函数开始深度优先搜索。

- `is_leaf`函数用来判断一个节点是否为叶子节点：

```cpp
bool is_leaf(TreeNode *t) {
    return !t->left && !t->right;  // 如果左右子节点都为空，就是叶子节点
}
```

- `dfs`函数是核心，它通过递归遍历整棵树。以上面的树为例，让我们看看处理过程：

从根节点 3 开始：

```cpp
int dfs(TreeNode *t) {  // t = 3
    int res = 0;

    // 处理左子树
    if (t->left) {  // 3有左节点9
        if (is_leaf(t->left)) {  // 9是叶子节点
            res += t->left->val;  // res += 9
        } else {
            res += dfs(t->left);  // 如果9不是叶子节点就继续递归
        }
    }

    // 处理右子树
    if (t->right && !is_leaf(t->right)) {  // 20不是叶子节点
        res += dfs(t->right);  // 递归处理20的子树
    }

    return res;
}
```

当递归到节点 20 时：

```cpp
int dfs(TreeNode *t) {  // t = 20
    int res = 0;

    if (t->left) {  // 20有左节点15
        if (is_leaf(t->left)) {  // 15是叶子节点
            res += t->left->val;  // res += 15
        }
    }

    // 右节点7是叶子节点，不需要继续递归

    return res;
}
```

这个算法的时间复杂度是 O(n)，其中 n 是树中的节点数，因为我们需要访问每个节点一次。空间复杂度在最坏情况下（树呈现为一条链）是 O(h)，其中 h 是树的高度，这是由于递归调用栈的开销。

2. 层序遍历 bfs

```cpp
class Solution
{
public:
    bool is_leaf(TreeNode *t)
    {
        return !t->left && !t->right;
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (root)
        {
            q.push(root);
        }
        int res = 0;

        while (!q.empty())
        {
            TreeNode *t = q.front();
            q.pop();

            if (t->left)
            {
                if (is_leaf(t->left))
                {
                    res += t->left->val;
                }
                else
                {
                    q.push(t->left);
                }
            }

            if (t->right && !is_leaf(t->right))
            {
                // 对于右子节点，我们只需要在它不是叶子节点的情况下将其加入队列即可。因为我们只需要计算左叶子节点的和，所以不需要考虑右叶子节点的值
                q.push(t->right);
            }
        }

        return res;
    }
};
```

时间复杂度：O(n)，其中 n 是树中的节点个数。

空间复杂度：O(n)。空间复杂度与广度优先搜索使用的队列需要的容量相关，为 O(n)
