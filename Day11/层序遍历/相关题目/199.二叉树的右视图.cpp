/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode *root)
    {
        // 只需要返回层序遍历中一层的最后元素即可
        vector<int> res;
        queue<TreeNode *> q;
        if (root)
        {
            q.push(root);
        }
        while (!q.empty())
        {
            int size = q.size();
            vector<int> vec;
            while (size--)
            {
                TreeNode *t = q.front();
                q.pop();
                vec.push_back(t->val);
                if (t->left)
                {
                    q.push(t->left);
                }
                if (t->right)
                {
                    q.push(t->right);
                }
            }
            res.push_back(vec.back());
        }

        return res;
    }
};
// @lc code=end
