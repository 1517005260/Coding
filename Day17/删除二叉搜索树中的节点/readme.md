# 删除二叉搜索树中的节点

例题：[leetcode 450 删除二叉搜索树中的节点](https://leetcode.cn/problems/delete-node-in-a-bst/description/)

相比于简单的插入操作，删除操作比较复杂，因为涉及到了修改树结构。删除的分类如下：

**情况 1: 欲删除节点无左子树**

```
     5
   /   \
  3     7    删除节点7
 /
2
```

当我们删除节点 7 时，由于它没有左子树，我们只需要将其右子树(这里是空)返回给其父节点即可。删除后的树变为：

```
     5
   /
  3
 /
2
```

**情况 2: 欲删除节点无右子树**

```
     5
   /   \
  3     7    删除节点3
 /       \
2         8
```

当删除节点 3 时，由于它没有右子树，我们只需要将其左子树(节点 2)返回给其父节点。删除后的树变为：

```
     5
   /   \
  2     7
         \
          8
```

**情况 3: 欲删除节点具有左右子树**

```
     5
   /   \
  3     8    删除节点5
 / \   / \
2   4 6   9
```

这是最复杂的情况。当删除节点 5 时，我们需要：

1. 找到右子树中的最小值(也就是右子树中最左边的节点，这里是 6 // 或者可以对称，找到左子树的最大值)
2. 用该值替换要删除的节点的值
3. 删除右子树中的那个最小值节点

处理后的树变为：

```
     6
   /   \
  3     8
 / \     \
2   4     9
```

代码如下：

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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
        {
            return nullptr;
        }

        // 首先，我们需要找到需要删除的节点
        if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            // 找到了要删掉的节点
            // 情况1
            if (!root->left)
            {
                return root->right;
            }

            // 情况2
            if (!root->right)
            {
                return root->left;
            }

            // 情况3
            // 首先需要找到右子树的最小值
            TreeNode *now = root->right;
            TreeNode *pre = root;

            bool flag = false; // 是否进入while循环

            while (now->left)
            {
                flag = true;
                pre = now;
                now = now->left;
            }

            // 现在now的左子树为空，now就是右子树的最左边的节点，即最小值
            // 只要删除now，now顶替root即可
            root->val = now->val;

            if (flag)
            {
                pre->left = now->right;
            }
            else
            {
                pre->right = now->right;
            }
        }
        return root;
    }
};
```

至于为什么要用 flag 来判断是否进入循环，我们可以用下例来说明：

```
     5 (要删除)
   /   \
  3     7
 /       \
2         8
```

now = 7, pre = 5

由于 7 没有左子树，所以不进循环。now->right =8

删除完成后：

```
    7
   /  \
  3    8
 /
2
```
