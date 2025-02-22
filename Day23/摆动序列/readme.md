# 摆动序列

例题：[leetcode 376 摆动序列](https://leetcode.cn/problems/wiggle-subsequence/description/)

**注意，子序列可以不连续地选择**

贪心策略：我们在每个位置都尽可能地选择能形成摆动的点。
正确性证明：

- 如果我们跳过了某个可以形成摆动的点，后面即使找到更多的点，也不可能得到更长的序列
- 因为摆动序列的核心是差值的正负交替，而不是差值的具体大小

```cpp
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return nums.size();
        }

        // 我们需要记录相邻的差值
        int curDiff = 0;
        int preDiff = 0;

        // 初始长度为1，因为第一个数字一定是序列的一部分
        int cnt = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            curDiff = nums[i] - nums[i - 1];

            // 贪心地找到摆动的序列
            // 如果当前差值和前一个差值满足摆动条件
            // (之前是上升，现在是下降) 或 (之前是下降，现在是上升) 或 (是第一段)
            if (curDiff > 0 && preDiff <= 0 || curDiff < 0 && preDiff >= 0)
            {
                cnt++;
                preDiff = curDiff;
            }
        }

        return cnt;
    }
};
```

理解"摆动"的本质：

1. 对于上升转下降的情况：

   - 当前差值必须严格小于 0（curDiff < 0）
   - 前一个差值需要大于等于 0（preDiff >= 0）
     包含等于 0 是为了处理序列开始的情况，以及处理平坦转下降的情况

2. 对于下降转上升的情况：
   - 当前差值必须严格大于 0（curDiff > 0）
   - 前一个差值需要小于等于 0（preDiff <= 0）
     同样，包含等于 0 是为了处理序列开始和平坦转上升的情况
