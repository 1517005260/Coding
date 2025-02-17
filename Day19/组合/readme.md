# 组合

例题：[leetcode 77 组合](https://leetcode.cn/problems/combinations/description/)

1. 全搜索法

只要注意利用 startIdx 来控制起始下标，使得不重复遍历即可

```cpp
class Solution
{
private:
    vector<vector<int>> _res; // 总共结果
    vector<int> _tmp;         // 单次结果

    // 根据模板写即可
    void dfs(int n, int k, int startIdx)
    {
        if (_tmp.size() == k)
        {
            _res.push_back(_tmp);
            return;
        }

        for (int i = startIdx; i <= n; i++)
        {
            _tmp.push_back(i);
            dfs(n, k, i + 1);
            _tmp.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        dfs(n, k, 1);
        return _res;
    }
};
```

时间复杂度：O(C(n,k) \* k)

- 总共会生成 C(n,k) 个组合
- 对于每个组合,需要花费 O(k) 的时间来构建结果
- 因此总的时间复杂度是 O(C(n,k) \* k)

空间复杂度：O(k)

- 递归深度是 k,因为每次递归都会记录一个数字,直到凑够 k 个数字
- \_tmp 数组的大小上限是 k
- \_res 数组用于存储最终结果,不计入递归的空间复杂度

2. 经过剪枝优化

一种常见的优化是，当最后剩的数字不足以凑够 k 个时，可以提前返回结果

```cpp
class Solution
{
private:
    vector<vector<int>> _res;
    vector<int> _tmp;
    void dfs(int n, int k, int startIdx)
    {
        if (_tmp.size() == k)
        {
            _res.push_back(_tmp);
            return;
        }

        for (int i = startIdx; i <= n - (k - _tmp.size()) + 1; i++)
        {
            _tmp.push_back(i);
            dfs(n, k, i + 1);
            _tmp.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        dfs(n, k, 1);
        return _res;
    }
};
```

假设 n = 4, k = 3，我们要从 1-4 中选择 3 个数

没有剪枝时的搜索过程：

- 如果我们选择了数字 3 作为第一个数，接下来只剩下 4 可以选
- 但是我们需要选 3 个数，显然是不可能完成的任务
- 这种情况下的搜索就是在做无用功

有剪枝时的优化：

- \_tmp.size() 表示当前已经选择的数字个数
- k - \_tmp.size() 表示还需要选择的数字个数
- n - (k - \_tmp.size()) + 1 就是我们最多能选择到的数字

时空复杂度不变
