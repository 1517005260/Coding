# 两个数组的交集

例题：[leetcode 349 两个数组的交集](https://leetcode.cn/problems/intersection-of-two-arrays/description/)

由于可以不考虑顺序，所以我们考虑用 set 解决交集问题

```cpp
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> res; // 存放结果，set用于去重
        // 对于大小为n的容器，下标0~n-1，begin()指向下标0，end()指向下标n
        unordered_set<int> num1_set(nums1.begin(), nums1.end()); // 存放num1的所有元素组成的集合

        for (int num : nums2) // for num2[i] in num2
        {
            if (num1_set.find(num) != num1_set.end())
            { // num1_set.end() 表示查找失败
                res.insert(num);
            }
        }

        return vector<int>(res.begin(), res.end()); // 将set转换为vector
    }
};
```

时间复杂度: O(n + m) m 是最后要把 set 转成 vector

空间复杂度: O(n)
