# 前 K 个高频元素

例题：[leetcode 347 前 K 个高频元素](https://leetcode.cn/problems/top-k-frequent-elements/description/)

最简单的思路就是使用`map<元素，元素出现次数>`来进行排序，按 value 值取前 k 大的 key 即可。（O(nlogn)）

但是实际上没有必要对所有元素进行排序，我们只要维护一个大小为 k 的小根堆即可。（O(nlogk)）

为什么不用大根堆？因为 pop 是顶部的元素，我们需要保留大元素 pop 小元素，所以用小根堆。

这里需要注意一下，c++中的小根堆创建逻辑：在优先队列中，默认是构造大顶堆，比较函数返回 true 时表示第一个参数应该排在第二个参数后面。所以当我们写：

```cpp
return l.second > r.second;
```

举个例子：

- 假设 l.second = 5, r.second = 3
- 5 > 3 返回 true
- 这表示 5 应该排在 3 的后面
- 所以 3 会在堆顶，5 在下面
- 这就形成了小顶堆

```cpp
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // 使用map来维护nums[i]出现的次数
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }

        // 创建小根堆
        priority_queue<
            pair<int, int>,                                // 堆的数据类型，即map
            vector<pair<int, int>>,                        // 底层用数组实现堆
            function<bool(pair<int, int>, pair<int, int>)> // 自定义比较函数
            >
            q // 优先队列名
            (
                // 匿名函数实现自定义比较逻辑
                // []为空不捕获任何外部变量
                [](const pair<int, int> &l, const pair<int, int> &r)
                {
                    return l.second > r.second;
                });

        // 维护大小为k的小根堆
        for (const auto &[num, freq] : map)
        {
            q.push({num, freq});
            if (q.size() > k)
            {
                q.pop();
            }
        }

        // 返回结果
        vector<int> res;
        for (int i = k - 1; i >= 0; i--)
        {
            res.push_back(q.top().first);
            q.pop();
        }

        return res;
    }
};
```

时间复杂度: O(nlogk)，空间复杂度: O(n)
