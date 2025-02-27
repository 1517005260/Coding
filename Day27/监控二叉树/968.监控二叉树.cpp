/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    int res = 0;

public:
    int minCameraCover(TreeNode *root)
    {
        if (dfs(root) == 0)
        {
            // 如果根节点未被监控
            res++;
        }

        return res;
    }

    // 定义三种状态
    // 0 - 未被监控
    // 1 - 被监控
    // 2 - 本节点t有摄像头
    int dfs(TreeNode *t)
    {
        if (!t)
        {
            // 如果t为空，那么说明t的父节点是叶子节点
            // 我们不能在叶子节点放摄像头
            // 所以为了统一处理，默认空节点是被监控的
            return 1;
        }

        // 自下而上，不在叶子上放摄像头
        // 左右中后续遍历可以自下而上

        int left = dfs(t->left);
        int right = dfs(t->right);

        // t是left和right的父亲
        // 一共有：00,01,02,11,12,22 这些状态

        // 左右孩子只要有一个未被覆盖，就需要t加一个摄像头来监控子节点
        // 00,01,02
        if (left == 0 || right == 0)
        {
            res++;
            return 2;
        }

        // 11 状态，左右孩子全被监控，此时t需要被他的父节点来监控
        if (left == 1 && right == 1)
        {
            return 0; // 此时t还未被监控
        }

        // 12 22 状态
        if (left + right >= 3)
        {
            // 子节点有摄像头，则t被监控到了
            return 1;
        }

        return -1; // 走不到这里
    }
};
// @lc code=end
