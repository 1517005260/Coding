# K 次取反后最大化的数组和

例题：[leetcode 1005 K 次取反后最大化的数组和](https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/description/)

贪心的思路，局部最优：让绝对值大的负数变为正数，当前数值达到最大，整体最优：整个数组和达到最大。

所以，我们可以：

- 首先按绝对值从大到小排序
- 之后从前向后遍历，如果碰到负数，就消耗 k 使得变正
- 如果最后 k 值还没消耗完，就对最后一个数（最小的正数）反复施加负号
- 最后求和

```cpp
class Solution
{
    // sort函数要求自定义比较函数为static
    static bool cmp(int a, int b)
    {
        return abs(a) > abs(b); // 按绝对值降序排列
    }

public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(), cmp);

        for (int i = 0; i < nums.size(); i++)
        {
            // 消耗k
            if (nums[i] < 0 && k > 0)
            {
                k--;
                nums[i] = -nums[i];
            }
        }

        // 如果k还有剩余
        // 如果是偶数，则对最后一个数施加符号相当于没做
        // 如果是奇数，那么就相当于加一次负号
        if (k % 2 == 1)
        {
            nums.back() = -nums.back();
        }

        int sum = 0;
        for (int num : nums)
        {
            sum += num;
        }
        return sum;
    }
};
```
