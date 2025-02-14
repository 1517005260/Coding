# 二叉树的最近公共祖先

例题：[leetcode 236 二叉树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/)

显然自底向上查找可以找到最近的公共祖先，而后序遍历（左右中）就可以达到自底向上的效果

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // p或q为root时，最近祖先就是root
        if (!root || p == root || q == root)
        {
            return root;
        }

        // 左右中
        // 分别在左右子树中寻找p和q
        // 返回值可能是：p、q、它们的公共祖先、或NULL
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
        {
            // 如果左右子树都返回非空值，说明p和q分别在当前节点的左右子树中。这种情况下，当前节点就是最近公共祖先
            return root;
        }

        // 如果只有一边子树返回非空值，说明p和q都在这边子树中，把这边子树的结果向上传递
        if (!left && right)
        {
            return right;
        }

        if (left && !right)
        {
            return left;
        }

        // !left && !right
        return nullptr;
    }
};
```

举例理解这个递归的过程：

假设我们要找节点 5 和节点 4 的最近公共祖先：

```
     3
   /   \
  5     1
 / \   / \
6   2 0   8
   / \
  7   4
```

执行过程：

1. 从根节点 3 开始：

   - 左子树搜索返回节点 5（因为 5 和 4 都在左子树）
   - 右子树搜索返回 NULL
   - 所以返回左子树的结果：节点 5

2. 在节点 5 处：
   - 左子树搜索返回 NULL（6 下面没有 4）
   - 右子树搜索返回节点 4（找到了 4）
   - 因为右子树找到了 4，且当前节点就是 5，所以返回 5

这就是为什么节点 5 被确定为最近公共祖先。代码通过递归的方式，自底向上地传递信息，最终找到了满足条件的节点。

除了递归法外，还可以使用 hash 来解决：

```cpp
class Solution
{
private:
    unordered_map<int, TreeNode *> _father; // 存储父节点 <节点值，节点的父节点>
    unordered_map<int, bool> _visited;      // 存储一个节点是否被访问

    void build_father(TreeNode *t)
    {
        if (!t)
        {
            return;
        }

        if (t->left)
        {
            _father[t->left->val] = t;
            build_father(t->left);
        }

        if (t->right)
        {
            _father[t->right->val] = t;
            build_father(t->right);
        }
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        _father[root->val] = nullptr; // 第一个节点没有父节点
        build_father(root);

        while (p)
        {
            _visited[p->val] = true;
            p = _father[p->val];
        }

        while (q)
        {
            if (_visited[q->val])
            {
                return q;
            }
            q = _father[q->val];
        }
        return nullptr;
    }
};
```

理解这个方法：

假设我们还是用这个树：

```
     3
   /   \
  5     1
 / \   / \
6   2 0   8
   / \
  7   4
```

第一步：构建父节点映射

```cpp
_father[root->val] = nullptr; // 先设置根节点3的父节点为空
build_father(root);           // 然后递归构建其他节点的父节点映射
```

通过递归，build_father 函数会构建出这样的映射关系：

```
_father[3] = nullptr  // 根节点
_father[5] = 3        // 5的父节点是3
_father[1] = 3        // 1的父节点是3
_father[6] = 5        // 6的父节点是5
_father[2] = 5        // 2的父节点是5
_father[0] = 1        // 0的父节点是1
_father[8] = 1        // 8的父节点是1
_father[7] = 2        // 7的父节点是2
_father[4] = 2        // 4的父节点是2
```

第二步：标记第一个节点的路径

```cpp
while (p) {
    _visited[p->val] = true;  // 标记当前节点为已访问
    p = _father[p->val];      // 移动到父节点
}
```

如果 p 是节点 5，这个循环会标记：

- \_visited[5] = true
- \_visited[3] = true // 5 的父节点
  这样就标记了从节点 5 到根节点的整条路径。

第三步：查找最近公共祖先

```cpp
while (q) {
    if (_visited[q->val]) {   // 如果当前节点已被访问过
        return q;             // 找到了最近公共祖先
    }
    q = _father[q->val];      // 否则继续向上查找父节点
}
```

如果 q 是节点 4，这个循环会：

1. 检查节点 4：未被访问
2. 移动到节点 2：未被访问
3. 移动到节点 5：已被访问！找到了最近公共祖先

这个方法的巧妙之处在于：

1. 它把树的结构转换成了更容易处理的父节点映射关系
2. 通过标记路径的方式，第一次相交的节点必然是最近公共祖先
3. 时间复杂度是 O(h)，h 是树的高度，空间复杂度是 O(n)用于存储父节点映射

这种解法本质上是把"自底向上找共同祖先"的问题转换成了"路径相交"的问题，使得问题更容易理解和解决。它就像在迷宫中找两条路径的第一个交点，很形象直观。
