# 斐波那契数

例题：[leetcode 509 斐波那契数](https://leetcode.cn/problems/fibonacci-number/description/)

1. 确定 dp 数组及下标 i 的含义：

这里，`dp[i]`代表第 i 个斐波那契数

2. 确定递推公式：

题干已经给我们了，就是`dp[i] = dp[i-1] + dp[i-2]`

3. 如何初始化？

体感也告诉我们了，就是`dp[0]=0, dp[1]=1`

4. 确定遍历的顺序

由`dp[i] = dp[i-1] + dp[i-2]`，显然从前向后遍历

5. 举例推导 dp 数组

```
0 1 1 2 3 5 8 13 21 34 55
```

如果提交发生错误，就 debug 看看实际的 dp 数组和我们推出来的有什么区别

```cpp
class Solution
{
public:
    int fib(int n)
    {
        int dp[35];

        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
```
