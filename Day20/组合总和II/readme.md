# 组合总和 II

例题：[leetcode 40 组合总和 II](https://leetcode.cn/problems/combination-sum-ii/description/)

本题的特点：

- candidates 里有重复元素
- 但是最后不能有重复解

进行去重操作，我们需要先对 candidates 进行排序，然后在 for 循环中，利用 startIdx 进行去重：

```cpp
class Solution
{
private:
    vector<vector<int>> _res;
    vector<int> _tmp;

    void dfs(vector<int> &candidates, int target, int startIdx)
    {
        if (target < 0)
        {
            return;
        }

        if (target == 0)
        {
            _res.push_back(_tmp);
            return;
        }

        for (int i = startIdx; i < candidates.size() && target - candidates[i] >= 0; i++) // 顺便剪枝
        {
            // 进行去重操作
            if (i > startIdx && candidates[i] == candidates[i - 1])
            {
                continue;
            }

            target -= candidates[i];
            _tmp.push_back(candidates[i]);
            dfs(candidates, target, i + 1); // 本题无重复解
            _tmp.pop_back();
            target += candidates[i];
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return _res;
    }
};
```
