# 将有序数组转换为二叉搜索树

例题：[leetcode 108 将有序数组转换为二叉搜索树](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/)

注意，本题的二叉搜索树必须**平衡**。

可以发现，我们只要从中间位置开始划分数组即可。至于奇数与偶数长度的数组，并无区别，无论取中间位置+/-1 的地方的元素，最后构造出来的树都是平衡的。

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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return dfs(nums, 0, nums.size() - 1);
    }

    TreeNode *dfs(vector<int> &nums, int start, int end)
    {
        if (!nums.size())
        {
            return nullptr;
        }

        if (start > end)
        {
            return nullptr;
        }

        int middle = (start + end) / 2;

        TreeNode *root = new TreeNode(nums[middle]);
        root->left = dfs(nums, start, middle - 1);
        root->right = dfs(nums, middle + 1, end);

        return root;
    }
};
```
