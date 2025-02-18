# 组合总和

例题：[leetcode 39 组合总和](https://leetcode.cn/problems/combination-sum/description/)

本题可以出现重复解，所以 dfs 下层的时候，startIdx 还可以为 i：

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

        for (int i = startIdx; i < candidates.size(); i++)
        {
            target -= candidates[i];
            _tmp.push_back(candidates[i]);
            dfs(candidates, target, i); // 可以出现重复解，所以startIdx可以不从i+1开始
            _tmp.pop_back();
            target += candidates[i];
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        dfs(candidates, target, 0);
        return _res;
    }
};
```

剪枝优化：我们先对 candidates 进行排序，比如结果是`[2,3,6,7]`，target=7，如果当前 dfs 层的和已经是 5，下一个数字是 7，显然超了，没必要继续尝试

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

        // 进行剪枝优化
        for (int i = startIdx; i < candidates.size() && target - candidates[i] >= 0; i++)
        {
            target -= candidates[i];
            _tmp.push_back(candidates[i]);
            dfs(candidates, target, i);
            _tmp.pop_back();
            target += candidates[i];
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return _res;
    }
};
```

- 时间复杂度: O(n \* 2^n)，注意这只是复杂度的上界，因为剪枝的存在，真实的时间复杂度远小于此
- 空间复杂度: O(target)
