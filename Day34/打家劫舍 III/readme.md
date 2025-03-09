# 打家劫舍 III

例题：[leetcode 337 打家劫舍 III](https://leetcode.cn/problems/house-robber-iii/description/)

首先我们要先定义树形下的递推公式：

我们需要为每个节点定义两种状态：

1. 偷当前节点：那么其所有子节点都不能偷
2. 不偷当前节点：那么其子节点可以偷也可以不偷（取最大收益）

这与前两个版本的核心思想是一致的，只是状态的存储和传递方式变了。

所以，这里的 dp 数组的含义是：

```
对于每个节点，都有自己的dp[2]数组，其中：

dp[0] 表示不偷本节点的最大收益
dp[1] 表示考虑本节点的最大收益
```

假设我们当前在考虑节点`cur`，它有左右子节点。我们已经计算出了左右子节点的状态：

- `left[0]`：不偷左子节点的最大收益
- `left[1]`：偷左子节点的最大收益
- `right[0]`：不偷右子节点的最大收益
- `right[1]`：偷右子节点的最大收益

那么`cur`节点的状态计算如下：

1. 如果偷当前节点：

   - 那么左右子节点都不能偷
   - `val1 = cur->val + left[0] + right[0]`

2. 如果不偷当前节点：
   - 左右子节点可以偷也可以不偷，取决于哪种方式收益更大
   - `val2 = max(left[0], left[1]) + max(right[0], right[1])`

当前节点的最终状态是：`{val2, val1}`，即`{不偷的最大收益, 偷的最大收益}` => `dp[0] = val2, dp[1] = val1`

由于依赖与子节点的状态，所以我们采用后序遍历，自下而上遍历整个树

```cpp
class Solution
{
public:
    int rob(TreeNode *root)
    {
        vector<int> res = postTree(root);
        return max(res[0], res[1]);
    }

    // 返回一个dp数组，dp[0] 表示不偷本节点的最大收益，dp[1]表示偷的最大收益
    vector<int> postTree(TreeNode *cur)
    {
        if (!cur)
        {
            return vector<int>{0, 0};
        }

        vector<int> left = postTree(cur->left);
        vector<int> right = postTree(cur->right);

        // 1. 偷cur，那么不偷左右节点
        int val1 = left[0] + right[0] + cur->val;

        // 2. 不偷cur，那么考虑左右节点的情况下取大值
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);

        return vector<int>{val2, val1};
    }
};
```
