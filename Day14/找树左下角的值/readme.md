# 找树左下角的值

例题：[leetcode 513 找树左下角的值](https://leetcode.cn/problems/find-bottom-left-tree-value/description/)

1. 最简单的方法，层序遍历每次都保留该层的首元素，最后返回即可

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
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;

        if (root)
        {
            q.push(root);
        }

        int res = 0;

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode *t = q.front();
                q.pop();

                if (i == 0)
                {
                    res = t->val;
                }

                if (t->left)
                {
                    q.push(t->left);
                }

                if (t->right)
                {
                    q.push(t->right);
                }
            }
        }

        return res;
    }
};
```

2. 如果尝试用递归法：深度最大的叶子节点一定是最后一行，我们采用前序遍历：

我们返回第一个更新最大深度的节点即可，它一定是最左边的。

```cpp
class Solution
{
private:
    int res = 0;
    int max_depth = INT_MIN;

public:
    int findBottomLeftValue(TreeNode *root)
    {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode *t, int depth)
    {
        if (!t->left && !t->right)
        {
            // 抵达叶子节点
            if (depth > max_depth)
            {
                // 只会在第一次抵达最深层时更新，所以一定是最左边的
                max_depth = depth;
                res = t->val;
            }
        }

        if (t->left)
        {
            dfs(t->left, depth + 1);
        }

        if (t->right)
        {
            dfs(t->right, depth + 1);
        }
    }
};
```
