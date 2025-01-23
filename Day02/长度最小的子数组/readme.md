# 长度最小的子数组

例题：[leetcode 209 长度最小的子数组](https://leetcode.cn/problems/minimum-size-subarray-sum/description/)

1. 暴力遍历（会超时）

```cpp
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int res = INT32_MAX; // 32位下最大int
        int sum = 0;         // 子数组的和，需要令其等于target
        int len = 0;         // 子数组的长度，需要令其最小
        for (int i = 0; i < nums.size(); i++)
        {
            sum = 0; // 每次遍历重置sum
            for (int j = i; j < nums.size(); j++)
            {
                // 向后遍历子数组
                sum += nums[j];
                if (sum >= target)
                {
                    len = j - i + 1;
                    res = res < len ? res : len;
                    break;
                }
            }
        }

        if (res == INT32_MAX)
        {
            return 0;
        }
        else
        {
            return res;
        }
    }
};
```

简单地遍历每个下标开始的子数组，时间复杂度 O(n²)，空间复杂度 O(1)。leetcode 的测试通过：`18/21 cases passed (N/A)`，报`Time Limit Exceeded`

2. 滑动窗口

滑动窗口可以看作双指针的变形，总体思路还是将两个 for 循环里做的事情优化到一个 for 循环里面。

其中，我们需要记录的是**滑动窗口的终止位置**。如果记录的是起始位置，那么其实和暴力法没有区别，因为我们还要找到符合条件的终止位置。

现在维护一个滑动窗口，要求窗口中的元素和大于等于 target。在此基础上，尝试缩小滑动窗口的大小，以返回最小的长度。

```cpp
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int res = INT32_MAX;
        int sum = 0;
        int i = 0; // 滑动窗口的起始位置
        int len = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            // 调整滑动窗口的末尾
            sum += nums[j];  // 扩大窗口

            // 尝试缩小滑动窗口
            while (sum >= target)
            {
                len = j - i + 1;
                res = res < len ? res : len;
                sum -= nums[i];
                i++;
            }
            // 如果缩小失败了，那么len不会被更新，len就是最小的长度
        }

        return res == INT32_MAX ? 0 : res;
    }
};
```

这个算法将暴力法优化到了 O(n)。举个例子来理解：

- nums = [2, 3, 1, 2, 4, 3]
- target = 7

```
步骤1: 初始状态
[2] 3 1 2 4 3
i,j
sum = 2 < 7, 继续扩大窗口

步骤2: 扩大窗口
[2 3] 1 2 4 3
i  j
sum = 5 < 7, 继续扩大窗口

步骤3: 扩大窗口
[2 3 1] 2 4 3
i    j
sum = 6 < 7, 继续扩大窗口

步骤4: 扩大窗口
[2 3 1 2] 4 3
i      j
sum = 8 >= 7, 找到一个符合的窗口！
当前长度 = 4
尝试缩小：移除2
 [3 1 2] 4 3
 i     j
sum = 6 < 7, 无法继续缩小

步骤5: 扩大窗口
[3 1 2 4] 3
 i      j
sum = 10 >= 7
当前长度 = 4
尝试缩小：移除3
  [1 2 4] 3
  i     j
sum = 7 = 7
当前长度 = 3
尝试缩小：移除1
   [2 4] 3
   i    j
sum = 6 < 7, 无法继续缩小

步骤6: 扩大窗口
[2 4 3]
   i   j
sum = 9 >= 7
当前长度 = 3
尝试缩小：移除2
    [4 3]
    i  j
sum = 7 = 7
当前长度 = 2 (找到最小长度！)
尝试缩小：移除4
     [3]
     i j
sum = 3 < 7, 无法继续缩小
```
