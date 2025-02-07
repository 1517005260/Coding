/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;

        if (root)
        {
            q.push(root);
        }

        int res = 0;

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode *t = q.front();
                q.pop();

                if (i == 0)
                {
                    res = t->val;
                }

                if (t->left)
                {
                    q.push(t->left);
                }

                if (t->right)
                {
                    q.push(t->right);
                }
            }
        }

        return res;
    }
};
// @lc code=end
