# 四数相加 II

例题：[leetcode 454 四数相加 II](https://leetcode.cn/problems/4sum-ii/description/)

map 的定义：`<数组元素的和, 该和的出现次数>`

分别遍历 AB 和 CD 两组数组，实现类似于[两数之和](../../Day05/两数之和/)的效果

```cpp
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> map;
        int cnt = 0;
        for (int a : nums1)
        {
            for (int b : nums2)
            {
                // 遍历这组数组的所有元素，存放至map<数组和，该和出现次数>
                map[a + b]++;
            }
        }

        for (int c : nums3)
        {
            for (int d : nums4)
            {
                int index = 0 - (c + d); // a + b的和
                if (map.find(index) != map.end())
                {
                    cnt += map[index];
                }
            }
        }

        return cnt;
    }
};
```

时间复杂度 O(n²)，空间复杂度 O(n²)（哈希表最坏情况下存储 n 平方个 key）
