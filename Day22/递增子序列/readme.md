# 递增子序列

例题：[leetcode 491 递增子序列](https://leetcode.cn/problems/non-decreasing-subsequences/description/)

最后返回的解不重复，这里我们使用`used[n]`数组进行去重，进行暴力搜索，如果数字 i 被用过了，那么`used[i] = true`

```cpp
class Solution
{
private:
    vector<vector<int>> res;
    vector<int> tmp;

    void dfs(vector<int> &nums, int startIdx)
    {
        if (tmp.size() >= 2)
        {
            res.push_back(tmp); // 根据题目要求，至少有两个元素
        }

        int used[201] = {0}; // 算法竞赛做法，这里有-100~100共201个数字
                             // 建立映射：-100 用过了，则used[0] = 1
        for (int i = startIdx; i < nums.size(); i++)
        {
            // 如果当前tmp非空且选中的元素非递增，或者选中重复元素，则跳过
            if ((!tmp.empty() && tmp.back() > nums[i]) || used[nums[i] + 100] == 1)
            {
                continue;
            }

            used[nums[i] + 100] = 1;
            tmp.push_back(nums[i]);
            dfs(nums, i + 1);
            tmp.pop_back();
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        dfs(nums, 0);
        return res;
    }
};
```

为什么这里不 return？：

```cpp
if (tmp.size() >= 2)
{
    res.push_back(tmp); // 根据题目要求，至少有两个元素
}
```

因为我们需要找到所有可能的非递减子序列,而不是找到一个就停止。如果在这里加了 return,会漏掉很多合法的序列。比如：

- 对于输入 `[4,6,7,7]`:
  - 当 tmp 为`[4,6]`时,虽然这是一个合法序列并且被加入到 res 中
  - 但如果这时 return 了,就会漏掉`[4,6,7]`和`[4,6,7,7]`这些更长的序列
  - 我们需要继续搜索,看看能不能在`[4,6]`的基础上构建更长的合法序列

这是一个典型的回溯算法模式:

- 每当找到一个合法解时,先保存下来
- 然后继续探索,看看能不能在这个解的基础上找到更多的解
- 直到无法再往下探索(触发 continue 或遍历完所有数字)才回溯

此外，这里不需要重置 used 数组：

```cpp
used[nums[i] + 100] = 1;
tmp.push_back(nums[i]);
dfs(nums, i + 1);
tmp.pop_back();
// 不需要 used[nums[i] + 100] = 0;
```

如下图所示：

![png](https://code-thinking-1253855093.file.myqcloud.com/pics/20201124200229824-20230310131640070.png)

同一父节点（同一层 dfs 里，即同一个 for 循环）下，它的子树是不能有重复元素的，否则会形成相同前缀，而同一分支（不同 dfs 层里），是允许重复元素的。
