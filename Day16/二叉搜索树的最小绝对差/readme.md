# 二叉搜索树的最小绝对差

例题：[leetcode 530 二叉搜索树的最小绝对差](https://leetcode.cn/problems/minimum-absolute-difference-in-bst/description/)

利用二叉搜索树是有序的这一性质，我们直接将其转为数组，在数组中操作即可。

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
    vector<int> _tree; //  二叉搜索树转为的数组

    void build(TreeNode *t)
    {
        if (!t)
        {
            return;
        }

        // 中序遍历构造有序数组
        build(t->left);
        _tree.push_back(t->val);
        build(t->right);
    }

public:
    int getMinimumDifference(TreeNode *root)
    {
        _tree.clear();
        build(root);

        int res = INT_MAX;

        for (int i = 1; i < _tree.size(); i++)
        {
            // 由于是有序的，所以 _tree[i] - _tree[i-1] 非负
            res = min(res, _tree[i] - _tree[i - 1]);
        }

        return res;
    }
};
```
