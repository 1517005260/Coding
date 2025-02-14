/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
    unordered_map<int, TreeNode *> _father; // 存储父节点 <节点值，节点的父节点>
    unordered_map<int, bool> _visited;      // 存储一个节点是否被访问

    void build_father(TreeNode *t)
    {
        if (!t)
        {
            return;
        }

        if (t->left)
        {
            _father[t->left->val] = t;
            build_father(t->left);
        }

        if (t->right)
        {
            _father[t->right->val] = t;
            build_father(t->right);
        }
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        _father[root->val] = nullptr; // 第一个节点没有父节点
        build_father(root);

        while (p)
        {
            _visited[p->val] = true;
            p = _father[p->val];
        }

        while (q)
        {
            if (_visited[q->val])
            {
                return q;
            }
            q = _father[q->val];
        }
        return nullptr;
    }
};
// @lc code=end
