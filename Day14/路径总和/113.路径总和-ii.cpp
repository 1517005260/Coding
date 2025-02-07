/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
private:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(TreeNode *t, int cnt)
    {
        if (!t->left && !t->right && cnt == 0)
        {
            res.push_back(path);
            return;
        }

        if (!t->left && !t->right)
        {
            return;
        }

        // dfs
        if (t->left)
        {
            path.push_back(t->left->val);
            cnt -= t->left->val;
            dfs(t->left, cnt);
            cnt += t->left->val;
            path.pop_back();
        }

        if (t->right)
        {
            path.push_back(t->right->val);
            cnt -= t->right->val;
            dfs(t->right, cnt);
            cnt += t->right->val;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        // 相当于清零操作
        res.clear();
        path.clear();

        if (!root)
        {
            return res;
        }

        path.push_back(root->val);
        dfs(root, targetSum - root->val);

        return res;
    }
};
// @lc code=end
