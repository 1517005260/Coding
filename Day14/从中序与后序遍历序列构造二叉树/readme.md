# 从中序与后序遍历序列构造二叉树

例题：[leetcode 106 从中序与后序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/)

![jpg](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)

例如，对于上述图片，中序遍历为：`[9,3,15,20,7]`，后序遍历为`[9,15,7,20,3]`

我们回忆一下 408 中的本考点的做法：

- 首先，需要找到后续遍历中的最后一个节点，也就是递归层中的根节点
- 其次，需要在中序遍历中找到它，那么中序遍历可以以它为切割点，左边是左子树，右边是右子树
- 对应地可以在后序数组中进行切割，之后递归处理即可

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
private:
    unordered_map<int, int> _inorder_map; // <a[i], i>
    vector<int> _post;                    // 便于参数传递，否则本题的函数传参还需要多写一个post数组，不如改成全局的

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            _inorder_map[inorder[i]] = i;
        }

        _post = postorder;
        TreeNode *t = build(0, inorder.size() - 1, 0, postorder.size() - 1);
        return t;
    }

    TreeNode *build(int inorderStart, int inorderEnd, int postStart, int postEnd)
    {
        if (inorderStart > inorderEnd || postStart > postEnd)
        {
            return nullptr;
        }

        // 取后序遍历中的最后一个元素作为本次递归的根节点
        int root = _post[postEnd];
        // 在中序遍历中找到它
        int inorder_root_idx = _inorder_map[root];

        TreeNode *t = new TreeNode(root);

        int left_size = inorder_root_idx - inorderStart;

        // 进行切割与递归
        t->left = build(inorderStart, inorder_root_idx - 1, postStart, postStart + left_size - 1);
        t->right = build(inorder_root_idx + 1, inorderEnd, postStart + left_size, postEnd - 1);

        return t;
    }
};
```

## 相关题目

[leetcode 105 从前序与中序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/)
