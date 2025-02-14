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
    unordered_map<int, int> _map; // <val, count>

    void build_map(TreeNode *t)
    {
        if (!t)
        {
            return;
        }

        _map[t->val]++;

        build_map(t->left);
        build_map(t->right);
    }

    // 返回count较大的
    // sort里用需要static
    bool static cmp(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        vector<int> res;

        if (!root)
        {
            return res;
        }

        build_map(root);

        // 现在需要对map进行排序，以出现频率降序
        vector<pair<int, int>> vec(_map.begin(), _map.end());
        sort(vec.begin(), vec.end(), cmp);

        // 现在可能有多个众数，需要全部返回
        res.push_back(vec[0].first);
        for (int i = 1; i < vec.size(); i++)
        {
            if (vec[i].second == vec[0].second)
            {
                res.push_back(vec[i].first);
            }
        }

        return res;
    }
};
// @lc code=end
