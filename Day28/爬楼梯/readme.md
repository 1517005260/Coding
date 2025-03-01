# 爬楼梯

例题：[leetcode 70 爬楼梯](https://leetcode.cn/problems/climbing-stairs/description/)

1. `dp[i]`的含义：爬到第 i 层楼梯，一共有`dp[i]`个不同的方法

2. 递推公式

每层楼梯的爬到方式可以由什么递推？

```
dp[i-1]：上到第i-1层楼梯，有dp[i-1]种方法，此时跨一步即可到第i层

dp[i-2]：上到第i-2层楼梯，有dp[i-2]种方法，此时跨两步也可到第i层

综上，dp[i] = dp[i-1] + dp[i-2]
```

3. 初始化：

```
dp[1]=1  // 爬到第一层楼梯只有一种方法
dp[2]=2  // 爬到第二层楼梯：可以一层一层爬，也可以一步直接上去
```

4. 遍历顺序：显然从底层向高层递推，即从前向后。

5. 举例验证：同上题[斐波那契数](../斐波那契数/)

```cpp
class Solution
{
public:
    int climbStairs(int n)
    {
        int dp[46];
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
```
