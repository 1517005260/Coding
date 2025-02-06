/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> path;
        build_path(root, "", path);
        return path;
    }

    void build_path(TreeNode *t, string cur_path, vector<string> &path)
    {
        if (t)
        {
            cur_path += to_string(t->val);

            // 判断有无后续节点
            if (!t->left && !t->right)
            {
                path.push_back(cur_path);
            }
            else
            {
                cur_path += "->";
                build_path(t->left, cur_path, path);
                build_path(t->right, cur_path, path);
            }
        }
    }
};
// @lc code=end
