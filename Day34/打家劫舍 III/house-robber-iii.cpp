/*
 * @lc app=leetcode.cn id=337 lang=cpp
 * @lcpr version=30100
 *
 * [337] 打家劫舍 III
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
// @lc code=end

/*
// @lcpr case=start
// [3,2,3,null,3,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,1,3,null,1]\n
// @lcpr case=end

 */
