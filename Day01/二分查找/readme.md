# 二分查找

例题：[Leetcode 704 二分查找](https://leetcode.cn/problems/binary-search/description/)

两种解法：

1. `[left, right]`时：

```cpp
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1; // 数组 [0, n]
        while (left <= right)        // [left, right]
        {
            int middle = (left + right) / 2;
            if (target > nums[middle])
            {
                left = middle + 1;
            }
            else if (target < nums[middle])
            {
                right = middle - 1;
            }
            else
            {
                return middle;
            }
        }
        return -1;
    }
};
```

2. `[left, right)`时：

```cpp
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();  // 数组 [0, n]
        while (left < right) // [left, right)
        {
            int middle = (left + right) / 2;
            if (target > nums[middle])
            {
                left = middle + 1;
            }
            else if (target < nums[middle])
            {
                right = middle;
            }
            else
            {
                return middle;
            }
        }
        return -1;
    }
};
```

总结：闭区间需要+1/-1，开区间原样就行。时间复杂度 O(log n)，空间复杂度 O(1)，因为只需要 left, right, middle 三个变量

## 相关题目

[leetcode 35 搜索插入位置](https://leetcode.cn/problems/search-insert-position/description/)

[leetcode 34 在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/)
