# 二叉搜索树中的众数

例题：[leetcode 501 二叉搜索树中的众数](https://leetcode.cn/problems/find-mode-in-binary-search-tree/description/)

1. 如果是普通二叉树，是无序的：

可以选择遍历时用 map 统计出现次数，众数即为出现次数最多的

```cpp
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
```

2. 如果是二叉搜索树，那么可以利用其中序遍历是有序的性质：

```cpp
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
```

二叉搜索树的一个重要性质是：通过中序遍历可以得到一个有序序列。这个性质对于查找众数特别有帮助，因为相同的数字在有序序列中一定是连续的。

比如对于树：

```
      2
     / \
    1   2
```

中序遍历会产生序列 `[1,2,2]`，相同的值会连续出现，使得我们可以直接通过比较相邻节点来统计频率。

相比第一种使用哈希表的方法，这种方法的优势在于：

- 空间复杂度更低：不需要额外的哈希表存储每个数字的出现次数
- 不需要排序：由于二叉搜索树的中序遍历本身就是有序的，我们可以在一次遍历中就完成所有工作
- 更优雅地处理了相同值的统计：利用了二叉搜索树的有序性质，避免了在无序树中需要的额外数据结构
