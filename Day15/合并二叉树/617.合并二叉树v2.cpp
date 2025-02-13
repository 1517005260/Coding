/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1)
        {
            return root2;
        }

        if (!root2)
        {
            return root1;
        }

        // 将 tree2 复制到 tree1
        queue<TreeNode *> q;
        q.push(root1);
        q.push(root2);

        while (!q.empty())
        {
            TreeNode *t1 = q.front();
            q.pop();

            TreeNode *t2 = q.front();
            q.pop();

            // 合并操作
            t1->val += t2->val;

            /*
            代码的目标是将两棵树合并到t1上，当t2某个位置为空时，保持t1原样即可
            情况1: t1左不空，t2左不空 -> 加入队列合并
            情况2: t1左空，t2左不空 -> 把t2节点赋给t1
            情况3: t1左不空，t2左空 -> 保持t1原样即可，不用特殊处理
            情况4: t1左空，t2左空 -> 都为空，不用处理
             */
            if (t1->left && t2->left)
            {
                q.push(t1->left);
                q.push(t2->left);
            }

            if (!t1->left && t2->left)
            {
                t1->left = t2->left;
            }

            if (t1->right && t2->right)
            {
                q.push(t1->right);
                q.push(t2->right);
            }

            if (!t1->right && t2->right)
            {
                t1->right = t2->right;
            }
        }
        return root1;
    }
};
// @lc code=end
