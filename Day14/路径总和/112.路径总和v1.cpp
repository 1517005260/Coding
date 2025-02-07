/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
// @lc code=end
