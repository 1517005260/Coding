# 二叉树的层序遍历（广度优先搜索）

例题：[leetcode 102 二叉树的层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/description/)

BFS 模板：采用队列，每次弹出一个元素，放入该元素的左右孩子。

![gif](https://code-thinking.cdn.bcebos.com/gifs/102%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.gif)

```cpp
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<vector<int>> res;

        if (root)
        {
            q.push(root);
        }

        while (!q.empty())
        {
            int size = q.size();
            vector<int> vec;
            while (size--)
            {
                TreeNode *t = q.front();
                q.pop();
                vec.push_back(t->val);
                if (t->left)
                {
                    q.push(t->left);
                }
                if (t->right)
                {
                    q.push(t->right);
                }
            }
            res.push_back(vec);
        }

        return res;
    }
};
```

时间复杂度：每个点进队出队各一次，故渐进时间复杂度为 O(n)。

空间复杂度：队列中元素的个数不超过 n 个，故渐进空间复杂度为 O(n)。

当然还可以使用递归法：

```cpp
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        order(root, res, 0);
        return res;
    }

    void order(TreeNode *t, vector<vector<int>> &res, int depth)
    {
        if (!t)
        {
            return;
        }

        if (res.size() == depth)
        {
            res.push_back(vector<int>()); // 需要新的一层
        }

        res[depth].push_back(t->val);
        order(t->left, res, depth + 1);
        order(t->right, res, depth + 1);
    }
};
```

理解：`if (res.size() == depth) res.push_back(vector<int>());`

我们手动模拟一下：

```
    3
   / \
  9  20
```

当递归执行时，depth 参数和 res.size()的变化是这样的：

1. 第一次调用（根节点 3）：

   - depth = 0
   - res.size() = 0
   - 0 == 0 条件成立，创建第一层数组
   - 结果：`[[3]]`

2. 处理左子节点 9 时：

   - depth = 1
   - res.size() = 1
   - 1 == 1 条件成立，创建第二层数组
   - 结果：`[[3], [9]]`

3. 处理右子节点 20 时：
   - depth = 1
   - res.size() = 2
   - 1 != 2 条件不成立，直接使用已存在的数组
   - 结果：`[[3], [9, 20]]`

## [Leetcode 相关题目](./相关题目/)

- [x] [107 二叉树的层序遍历 II](https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/description/)
- [x] [199 二叉树的右视图](https://leetcode.cn/problems/binary-tree-right-side-view/description/)
- [x] [637 二叉树的层平均值](https://leetcode.cn/problems/average-of-levels-in-binary-tree/description/)
- [x] [429 N 叉树的层序遍历](https://leetcode.cn/problems/n-ary-tree-level-order-traversal/description/)
- [x] [515 在每个树行中找最大值](https://leetcode.cn/problems/find-largest-value-in-each-tree-row/description/)
- [x] [116 填充每个节点的下一个右侧节点指针](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/description/)
- [x] [117 填充每个节点的下一个右侧节点指针 II](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/description/)
