# 最大二叉树

例题：[leetcode 654 最大二叉树](https://leetcode.cn/problems/maximum-binary-tree/description/)

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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return build(nums, 0, nums.size() - 1);
    }

    TreeNode *build(vector<int> &nums, int start_idx, int end_idx)
    {
        if (start_idx > end_idx)
        {
            return nullptr;
        }

        int max_index = get_max_index(nums, start_idx, end_idx);
        TreeNode *t = new TreeNode(nums[max_index]);

        t->left = build(nums, start_idx, max_index - 1);
        t->right = build(nums, max_index + 1, end_idx);

        return t;
    }

    int get_max_index(vector<int> &nums, int start_idx, int end_idx)
    {
        int res = start_idx;

        for (int i = start_idx + 1; i <= end_idx; i++)
        {
            if (nums[i] > nums[res])
            {
                res = i;
            }
        }

        return res;
    }
};
```
