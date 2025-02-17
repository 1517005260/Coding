# 组合总和 III

例题：[leetcode 216 组合总和 III](https://leetcode.cn/problems/combination-sum-iii/description/)

定义一个 targetSum，初始为 n，每次递归时减去当前值，若最后为 0 则符合条件

```cpp
class Solution
{
private:
    vector<vector<int>> _res;
    vector<int> _tmp;

    void dfs(int k, int targetSum, int startIdx)
    {
        if (_tmp.size() == k)
        {
            if (targetSum == 0)
            {
                _res.push_back(_tmp);
            }
            return;
        }

        for (int i = startIdx; i <= 9 - (k - _tmp.size()) + 1; i++) // 同上题的剪枝操作
        {
            targetSum -= i;
            _tmp.push_back(i);
            dfs(k, targetSum, i + 1);
            _tmp.pop_back();
            targetSum += i;
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        dfs(k, n, 1);
        return _res;
    }
};
```
