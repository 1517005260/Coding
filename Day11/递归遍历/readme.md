# 二叉树的递归遍历（深度优先搜索）

三种方法：

- 前序遍历（前根遍历）：中-左-右
- 中序遍历（中根遍历）：左-中-右
- 后序遍历（后根遍历）：左-右-中

## 例题

1. [leetcode 144 二叉树的前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal/description/)

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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        front(root, res);
        return res;
    }

    void front(TreeNode *t, vector<int> &res)
    {
        if (t == nullptr)
        {
            return;
        }

        res.push_back(t->val);
        front(t->left, res);
        front(t->right, res);
    }
};
```

时间复杂度：O(n)，其中 n 是二叉树的节点数。每一个节点恰好被遍历一次。

空间复杂度：O(n)，为递归过程中栈的开销，平均情况下为 O(logn)，最坏情况下树呈现链状，为 O(n)。

2. [leetcode 145 二叉树的后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal/description/)

```cpp
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        behind(root, res);
        return res;
    }

    void behind(TreeNode *t, vector<int> &res)
    {
        if (t == nullptr)
        {
            return;
        }

        behind(t->left, res);
        behind(t->right, res);
        res.push_back(t->val);
    }
};
```

3. [leetcode 94 二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/description/)

```cpp
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        middle(root, res);
        return res;
    }

    void middle(TreeNode *t, vector<int> &res)
    {
        if (t == nullptr)
        {
            return;
        }

        middle(t->left, res);
        res.push_back(t->val);
        middle(t->right, res);
    }
};
```
