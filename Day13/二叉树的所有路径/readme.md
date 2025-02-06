# 二叉树的所有路径

例题：[leetcode 257 二叉树的所有路径](https://leetcode.cn/problems/binary-tree-paths/description/)

1. dfs：递归向下遍历即可

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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> path;
        build_path(root, "", path);
        return path;
    }

    void build_path(TreeNode *t, string cur_path, vector<string> &path)
    {
        if (t)
        {
            cur_path += to_string(t->val);

            // 判断有无后续节点
            if (!t->left && !t->right)
            {
                path.push_back(cur_path);
            }
            else
            {
                cur_path += "->";
                build_path(t->left, cur_path, path);
                build_path(t->right, cur_path, path);
            }
        }
    }
};
```

理解回溯：

假设我们有这样一个简单的二叉树：

```
     1
   /   \
  2     3
 /
4
```

一步步模拟 DFS 遍历过程：

1. 首先调用 `binaryTreePaths(root)`，开始第一次 `build_path` 调用：

   ```
   build_path(1, "", path)
   - cur_path = "1"
   - 节点1有子节点，添加 "->"
   - cur_path = "1->"
   ```

2. 递归到左子树：

   ```
   build_path(2, "1->", path)
   - cur_path = "1->2"
   - 节点2有左子节点，添加 "->"
   - cur_path = "1->2->"
   ```

3. 继续递归到节点 4：

   ```
   build_path(4, "1->2->", path)
   - cur_path = "1->2->4"
   - 节点4是叶子节点（没有左右子节点）
   - 将 "1->2->4" 加入 path 数组
   ```

4. 回溯到节点 2，尝试右子树：

   ```
   build_path(nullptr, "1->2->", path)
   - 因为是空节点，直接返回
   ```

5. 回溯到节点 1，访问右子树：
   ```
   build_path(3, "1->", path)
   - cur_path = "1->3"
   - 节点3是叶子节点
   - 将 "1->3" 加入 path 数组
   ```

最终的 path 数组将包含两条路径：

- "1->2->4"
- "1->3"

时间复杂度

- O(N²)，其中 N 表示节点数目。在深度优先搜索中每个节点会被访问一次且只会被访问一次，每一次会对 `path` 变量进行拷贝构造，时间代价为 O(N)，故时间复杂度为 O(N²)。

空间复杂度

- O(N²)，其中 N 表示节点数目。除答案数组外我们需要考虑递归调用的栈空间：
  - 最坏情况：当二叉树中每个节点只有一个孩子节点时，即整棵二叉树呈一个链状，此时递归的层数为 N，此时每一层的 `path` 变量的空间代价的总和为 O(∑ᵢ₌₁ⁿ i) = O(N²)，空间复杂度为 O(N²)。
  - 最好情况：当二叉树为平衡二叉树时，它的高度为 log N，此时空间复杂度为 O((log N)²)。

2. 层序遍历 bfs：

我们开两个队列来模拟：

```cpp
class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;

        queue<TreeNode *> node;
        queue<string> path;

        if (root)
        {
            node.push(root);
            path.push(to_string(root->val));
        }

        while (!node.empty())
        {
            TreeNode *t = node.front();
            node.pop();
            string p = path.front();
            path.pop();

            if (!t->left && !t->right)
            {
                res.push_back(p);
            }
            else
            {
                if (t->left)
                {
                    node.push(t->left);
                    path.push(p + "->" + to_string(t->left->val));
                }

                if (t->right)
                {
                    node.push(t->right);
                    path.push(p + "->" + to_string(t->right->val));
                }
            }
        }

        return res;
    }
};
```

简单模拟下：

假设我们有这样一个二叉树:

```
     1
   /   \
  2     3
   \
    5
```

来看看算法是如何一步步执行的:

1. 初始状态:

   - node 队列: `[1]`
   - path 队列: `["1"]`
   - 结果 res: []

2. 处理节点 1:

   - 弹出 node(1)和 path("1")
   - 1 有左右子节点,所以:
   - node 队列: `[2, 3]`
   - path 队列: `["1->2", "1->3"]`
   - 结果 res: []

3. 处理节点 2:

   - 弹出 node(2)和 path("1->2")
   - 2 只有右子节点,所以:
   - node 队列: `[3, 5]`
   - path 队列: `["1->3", "1->2->5"]`
   - 结果 res: []

4. 处理节点 3:

   - 弹出 node(3)和 path("1->3")
   - 3 是叶子节点,所以:
   - node 队列: `[5]`
   - path 队列: `["1->2->5"]`
   - 结果 res: `["1->3"]`

5. 处理节点 5:
   - 弹出 node(5)和 path("1->2->5")
   - 5 是叶子节点,所以:
   - node 队列: []
   - path 队列: []
   - 结果 res: `["1->3", "1->2->5"]`

最终输出: `["1->3", "1->2->5"]`
