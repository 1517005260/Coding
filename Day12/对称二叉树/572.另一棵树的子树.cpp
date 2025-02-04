/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        // 复用 100. 相同的树 的逻辑
        // 向root中递归寻找与subRoot相同的树
        if (!root)
        {
            return false;
        }

        if (isSameTree(root, subRoot))
        {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        queue<TreeNode *> que;

        que.push(p);
        que.push(q);

        while (!que.empty())
        {
            TreeNode *first = que.front();
            que.pop();
            TreeNode *second = que.front();
            que.pop();

            if (!first && !second)
            {
                continue;
            }

            if ((!first && second) || (first && !second) || (first->val != second->val))
            {
                return false;
            }

            que.push(first->left);
            que.push(second->left);

            que.push(first->right);
            que.push(second->right);
        }

        return true;
    }
};
// @lc code=end
