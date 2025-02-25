# 分发糖果

例题：[leetcode 135 分发糖果](https://leetcode.cn/problems/candy/description/)

同时考虑两边会顾此失彼，所以我们一边一边看。

首先从前向后遍历，看`ratings[i]`和`ratings[i-1]`的制约。之后从后向前遍历，看`ratings[i]`和`ratings[i+1]`的制约。

想要同时满足两条制约规则，只要在两次遍历中取最大值即可。

```cpp
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        // 从前向后遍历的分配结果
        // 需要确保每人至少一颗糖
        vector<int> left(ratings.size(), 1);

        // 从后向前遍历的分配结果
        vector<int> right(ratings.size(), 1);

        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                left[i] = left[i - 1] + 1;
            }
        }

        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                right[i] = right[i + 1] + 1;
            }
        }

        int sum = 0;
        for (int i = 0; i < ratings.size(); i++)
        {
            sum += max(left[i], right[i]);
        }
        return sum;
    }
};
```

正确性分析：

采用了"两次遍历"的策略，分别处理左右两个方向的约束条件：

- 初始化: 所有孩子先分配 1 颗糖果（满足最低要求）
- 从左到右遍历: 确保右边评分更高的孩子比左边的孩子获得更多糖果
- 从右到左遍历: 确保左边评分更高的孩子比右边的孩子获得更多糖果
- 取两次结果的最大值: 同时满足左右两个方向的约束
