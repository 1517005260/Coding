# 平衡二叉树

例题：[leetcode 110 平衡二叉树](https://leetcode.cn/problems/balanced-binary-tree/description/)

平衡二叉树定义为：一个二叉树每个节点的左右两个子树的高度差的绝对值不超过 1

- 二叉树的高度就等于它的最大深度

1. 依据定义，我们可以写出如下算法：

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
    bool isBalanced(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }

        return isBalanced(root->left) && isBalanced(root->right) && abs(get_height(root->left) - get_height(root->right)) <= 1;
    }

    int get_height(TreeNode *t)
    {
        if (!t)
        {
            return 0;
        }
        return 1 + max(get_height(t->left), get_height(t->right));
    }
};
```

- 时间复杂度：$ O(n^2) $，其中 $ n $ 是二叉树中的节点个数。
  最坏情况下，二叉树是满二叉树，需要遍历二叉树中的所有节点，时间复杂度是 $ O(n) $。
  对于节点 $ p $，如果它的高度是 $ d $，则 `get_height(p)` 最多会被调用 $ d $ 次（即遍历到它的每一个祖先节点时）。对于平均的情况，一棵树的高度 $ h $ 满足 $ O(h) = O(\log n) $，因为 $ d \leq h $，所以总时间复杂度为 $ O(n \log n) $。对于最坏的情况，二叉树形成链式结构，高度为 $ O(n) $，此时总时间复杂度为 $ O(n^2) $。

- 空间复杂度：$ O(n) $，其中 $ n $ 是二叉树中的节点个数。空间复杂度主要取决于递归调用的层数，递归调用的层数不会超过 $ n $。

2. 显然上述方法可以优化，因为对于同一个节点，函数 get_height 会被重复调用，导致时间复杂度较高。如果使用自底向上的做法，则对于每个节点，函数 get_height 只会被调用一次

![png](https://code-thinking-1253855093.file.myqcloud.com/pics/20210203155515650.png)

如图，这是高度和深度的区别，方法 1 实际上求的是深度，是从上至下的，实际上是前序遍历（根左右），层层向下求深度。

我们这里可以优化为求高度，是自下而上的，由左右节点的高度可以推出根节点的高度，实际上是后序遍历（左右根）。

```cpp
class Solution
{
private:
    bool _res = true;

public:
    bool isBalanced(TreeNode *root)
    {
        int height = helper(root);
        return _res;
    }

    int helper(TreeNode *t)
    {
        if (!t)
        {
            return 0;
        }

        int left_height = 1 + helper(t->left);
        int right_height = 1 + helper(t->right);

        if (abs(left_height - right_height) > 1)
        {
            _res = false;
        }

        // 返回子树高度
        return max(left_height, right_height);
    }
};
```

时间复杂度：O(n)，其中 n 是二叉树中的节点个数。使用自底向上的递归，每个节点的计算高度和判断是否平衡都只需要处理一次，最坏情况下需要遍历二叉树中的所有节点，因此时间复杂度是 O(n)。

空间复杂度：O(n)，其中 n 是二叉树中的节点个数。空间复杂度主要取决于递归调用的层数，递归调用的层数不会超过 n。
