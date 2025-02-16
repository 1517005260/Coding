/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */

// @lc code=start
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
// @lc code=end
