# 有序数组的平方

例题：[leetcode 977 有序数组的平方](https://leetcode.cn/problems/squares-of-a-sorted-array/description/)

1. 暴力法

```cpp
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};
```

其中，遍历复杂度 O(n)，排序是快速排序，时间复杂度 O(log n)

2. 双指针法

由于平方性质，最小的数一定在中间，最大的数一定在两端

```cpp
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int k = nums.size() - 1;
        vector<int> res(nums.size(), 0);
        for (int i = 0, j = nums.size() - 1; i <= j;)
        {
            if (abs(nums[i]) > abs(nums[j]))
            {
                res[k] = nums[i] * nums[i];
                k--;
                i++;
            }
            else
            {
                res[k] = nums[j] * nums[j];
                k--;
                j--;
            }
        }
        return res;
    }
};
```

时间复杂度 O(n)
