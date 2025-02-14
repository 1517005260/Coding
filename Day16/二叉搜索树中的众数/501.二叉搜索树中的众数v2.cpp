/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    int _max_count = 0;       // 存储众数的出现频率
    int _cnt = 0;             // 存储当前元素的出现频率
    TreeNode *_pre = nullptr; // 上一个节点
    vector<int> _modes;       // 存储当前找到的所有众数

    // 二叉搜索树的中序遍历
    void dfs(TreeNode *cur)
    {
        if (!cur)
        {
            return;
        }

        dfs(cur->left);

        if (!_pre)
        {
            // 如果是第一个节点
            _cnt = 1;
        }
        else if (_pre->val == cur->val)
        {
            _cnt++;
        }
        else if (_pre->val != cur->val)
        {
            // 两个节点的数值不同，重新更新cnt
            _cnt = 1;
        }

        _pre = cur;

        if (_cnt == _max_count)
        {
            _modes.push_back(cur->val);
        }

        // 如果发现了比当前众数的出现频率，那么cur才是众数
        if (_cnt > _max_count)
        {
            _modes.clear(); // 之前的众数都失效了
            _max_count = _cnt;
            _modes.push_back(cur->val);
        }

        dfs(cur->right);
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        _modes.clear();
        dfs(root);
        return _modes;
    }
};
// @lc code=end
