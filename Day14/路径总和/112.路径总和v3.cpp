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
// @lc code=end
