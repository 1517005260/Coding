# 路径总和

例题：[leetcode 112 路径总和](https://leetcode.cn/problems/path-sum/description/)

![png](https://code-thinking-1253855093.file.myqcloud.com/pics/2021020316051216.png)

1. dfs 完整版

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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return false;
        }
        return dfs(root, targetSum - (root->val));
    }

    bool dfs(TreeNode *t, int cnt)
    {
        if (!t->left && !t->right && cnt == 0)
        {
            // 如果cnt被正好消耗完
            return true;
        }

        // 否则
        if (!t->left && !t->right)
        {
            return false;
        }

        if (t->left)
        {
            cnt -= t->left->val;
            if (dfs(t->left, cnt))
            {
                return true;
            }
            // 回溯
            cnt += t->left->val;
        }

        if (t->right)
        {
            cnt -= t->right->val;
            if (dfs(t->right, cnt))
            {
                return true;
            }
            cnt += t->right->val;
        }

        return false;
    }
};
```

2. dfs 精简版

```cpp
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return false;
        }

        if (!root->left && !root->right && root->val == targetSum)
        {
            return true;
        }

        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};
```

3. 迭代法模拟 dfs

```cpp
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        // 使用栈模拟dfs
        if (!root)
        {
            return false;
        }

        // <节点，和>
        stack<pair<TreeNode *, int>> s;
        s.push(pair<TreeNode *, int>(root, root->val));

        while (!s.empty())
        {
            pair<TreeNode *, int> node = s.top();
            s.pop();

            if (!node.first->left && !node.first->right && node.second == targetSum)
            {
                return true;
            }

            // 左子树优先遍历，栈先进后出
            if (node.first->right)
            {
                s.push(pair<TreeNode *, int>(node.first->right, node.second + node.first->right->val));
            }

            if (node.first->left)
            {
                s.push(pair<TreeNode *, int>(node.first->left, node.second + node.first->left->val));
            }
        }

        return false;
    }
};
```

## 相关题目

[leetcode 113 路径总和 II](https://leetcode.cn/problems/path-sum-ii/description/)（DFS 应用）
