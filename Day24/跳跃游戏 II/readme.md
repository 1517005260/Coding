# 跳跃游戏 II

例题：[leetcode 45 跳跃游戏 II](https://leetcode.cn/problems/jump-game-ii/description/)

在[上道题](../跳跃游戏/)的基础上，我们要求到达终点的最小步数

如图，如果移动下标达到了当前这一步的最大覆盖最远距离了，还没有到终点的话，那么就必须再走一步来增加覆盖范围，直到覆盖范围覆盖了终点。

![png](https://code-thinking-1253855093.file.myqcloud.com/pics/20201201232309103.png)

```cpp
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return 0;
        }

        int cnt = 0;

        int curCover = 0;  // 当前的最大覆盖下标
        int nextCover = 0; // 走下一步后的最大覆盖下标

        for (int i = 0; i < nums.size(); i++)
        {
            // 将走未走
            nextCover = max(nextCover, nums[i] + i);

            if (i == curCover)
            {
                // 走到了当前的最大位置，必须走下一步了
                cnt++;
                curCover = nextCover;
                if (curCover >= nums.size() - 1)
                {
                    break;
                }
            }
        }

        return cnt;
    }
};
```
