/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        // 层序遍历+求均值即可
        vector<double> res;
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
                vec.push_back(t->val);
                q.pop();
                if (t->left)
                {
                    q.push(t->left);
                }
                if (t->right)
                {
                    q.push(t->right);
                }
            }

            double avg = 0;
            double sum = 0;
            for (int num : vec)
            {
                sum += num;
            }
            avg = sum / vec.size();
            res.push_back(avg);
        }

        return res;
    }
};
// @lc code=end
