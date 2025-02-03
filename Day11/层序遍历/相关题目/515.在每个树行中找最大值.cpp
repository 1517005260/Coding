/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode *root)
    {
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

            int num = INT_MIN; // -2147483648
            for (int n : vec)
            {
                num = max(num, n);
            }
            res.push_back(num);
        }

        return res;
    }
};
// @lc code=end
