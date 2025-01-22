# 移除元素

例题：[leetcode 27 移除元素](https://leetcode.cn/problems/remove-element/description/)

两种解法：

1. 暴力法：

```cpp
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == val)
            {
                // 将 i 以后的所有元素向前移动
                for (int j = i + 1; j < size; j++)
                {
                    nums[j - 1] = nums[j];
                }
                // 更新 nums 数组
                i--;
                size--;
            }
        }
        return size;
    }
};
```

两层循环，时间复杂度 O(n²)，空间复杂度 O(1)

2. 双指针法：

将两次循环优化到一次。

fast 指针用于寻找满足条件的元素。slow 用于指明新数组的边界。

```cpp
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++)
        {
            if (nums[fast] != val) // 不是要删除的元素，即满足条件，需要加入新数组里
            {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};
```

举例：移除 val==3

```
初始状态：
fast: f
      [3, 2, 2, 3]
slow: s

第一步：fast看到3==val，不操作，fast前进
fast:    f
      [3, 2, 2, 3]
slow: s

第二步：fast看到2!=val，把2复制到slow位置，slow前进
fast:       f
      [2, 2, 2, 3]
slow:    s

第三步：fast看到2!=val，把2复制到slow位置，slow前进
fast:          f
      [2, 2, 2, 3]
slow:       s

第四步：fast看到3==val，不操作，fast前进到结束
fast:              f
      [2, 2, 2, 3]
slow:       s

结束：返回slow=2，表示新数组有效长度为2
最终有效数组：[2,2]
```

时间复杂度 O(n)，空间复杂度 O(1)
