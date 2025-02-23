# 跳跃游戏

例题：[leetcode 55 跳跃游戏](https://leetcode.cn/problems/jump-game/description/)

我们引入覆盖数组解决这个问题：

![png](https://code-thinking-1253855093.file.myqcloud.com/pics/20230203105634.png)

如图，只要能覆盖到最后一个下标，那么就返回 true，否则返回 false

```cpp
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return true;
        }

        int cover = 0;
        for (int i = 0; i <= cover; i++)
        {
            cover = max(cover, i + nums[i]);

            if (cover >= nums.size() - 1)
            {
                return true;
            }
        }

        return false;
    }
};
```
