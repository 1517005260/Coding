# 最大子序和

例题：[leetcode 53 最大子序和](https://leetcode.cn/problems/maximum-subarray/description/)

本题的子序列需要**连续地选择**

贪心的思想:如果当前累加和已经小于等于 0 了,那么对于后面的元素来说,保留这个负数的累加和没有任何意义,因为:

- 如果后面的数是正数,从后面这个正数重新开始会得到更大的和
- 如果后面的数是负数,包含当前负的累加和只会让结果变得更差

```cpp
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int res = INT32_MIN;

        int sum = 0;
        for (int num : nums)
        {
            sum += num;
            res = max(res, sum);

            if (sum <= 0)
            {
                sum = 0;
            }
        }

        return res;
    }
};
```
