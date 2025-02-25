# 加油站

例题：[leetcode 134 加油站](https://leetcode.cn/problems/gas-station/description/)

题意即，给定 gas 和 cost 数组，问我们从哪个下标 i 出发，可以走一圈回来。油箱初始为空，经过 i，就补充`gas[i]`，消耗`cost[i]`。解唯一。

新定义 rest 数组，即为 gas-cost，如果 rest 之和为 0，说明找不到可行解，因为总 gas 小于总 cost，否则有解。

```cpp
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int startIdx = 0; // 起始位置
        int curSum = 0;   // 当前油量盈亏
        int totalSum = 0; // 总油量盈亏

        for (int i = 0; i < gas.size(); i++)
        {
            int rest = gas[i] - cost[i];

            curSum += rest;
            totalSum += rest;

            if (curSum < 0)
            {
                // 当前油量为亏，说明这不是可行解，需要从i+1出发再试
                startIdx = i + 1;
                curSum = 0;
            }
        }

        if (totalSum < 0)
        {
            // 总油量盈亏为负
            return -1;
        }

        return startIdx;
    }
};
```
