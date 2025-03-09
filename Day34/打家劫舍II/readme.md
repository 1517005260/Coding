# 打家劫舍 II

例题：[leetcode 213 打家劫舍 II](https://leetcode.cn/problems/house-robber-ii/description/)

本题在打家劫舍的基础上，加上了首尾相邻的限制。

我们把这个问题分解成两个子问题：

1. 考虑`[0, n-2]`的所有情况
2. 考虑`[1, n-1]`的所有情况

即：

- 如果偷第一间房屋，那么最后一间就不能偷（子问题 1）
- 如果偷最后一间房屋，那么第一间就不能偷（子问题 2）
- 如果既不偷第一间也不偷最后一间，那么答案肯定不会超过上面两种情况

所以，两个子问题取大值即可。

**这种处理环形问题的技巧在很多场景中都有应用。它的核心思想是：将环形问题转化为多个线性问题，然后综合各个线性问题的解得到环形问题的解。**

```cpp
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return nums[0];
        }
        if (n == 2)
        {
            return max(nums[0], nums[1]);
        }

        vector<int> dp1(n - 1, 0);
        vector<int> dp2(n, 0);

        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        for (int i = 2; i <= n - 2; i++)
        {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
        }

        dp2[1] = nums[1];
        dp2[2] = max(nums[1], nums[2]);
        for (int i = 3; i <= n - 1; i++)
        {
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
        }

        return max(dp1[n - 2], dp2[n - 1]);
    }
};
```
