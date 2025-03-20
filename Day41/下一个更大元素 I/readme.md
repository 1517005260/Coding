# 下一个更大元素 I

例题：[leetcode 496 下一个更大元素 I](https://leetcode.cn/problems/next-greater-element-i/description/)

这里需要快速找到`nums1[i]`和`nums2[j]`，首先想到用 hash 来存储。

思路还是和[每日温度](../每日温度/)一样，维护一个从栈顶到栈底递增的单调栈。

### 示例

以测试用例 `nums1 = [4,1,2]` 和 `nums2 = [1,3,4,2]` 为例，逐步分析：

- **构建映射表**：

  - 映射：{ 4: 0, 1: 1, 2: 2 }

- **遍历 nums2**：

  1. **j = 0**，nums2[0] = 1
     - 栈为空，直接入栈：stack = [0]
  2. **j = 1**，nums2[1] = 3
     - 比较栈顶：nums2[s.top()] = nums2[0] = 1
     - 3 > 1，弹出 0；判断 1 是否在映射表中，存在，对应下标为 1，于是更新：res[1] = 3
     - 栈为空，将 j=1 入栈：stack = [1]
  3. **j = 2**，nums2[2] = 4
     - 比较栈顶：nums2[s.top()] = nums2[1] = 3
     - 4 > 3，弹出 1；判断 3 是否在映射表中，3 不存在于 nums1，所以不更新
     - 栈为空，将 j=2 入栈：stack = [2]
  4. **j = 3**，nums2[3] = 2
     - 比较栈顶：nums2[s.top()] = nums2[2] = 4
     - 2 < 4，不弹出，直接入栈：stack = [2, 3]

- **结束遍历**：

  - 最终，res 数组为：
    - 对应 nums1[0] = 4，没有找到更大元素 → -1
    - 对应 nums1[1] = 1，下一个更大元素为 3 → 3
    - 对应 nums1[2] = 2，没有找到更大元素 → -1

- **返回结果**：[-1, 3, -1]

```cpp
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res(nums1.size(), -1); // 依题意不满足是-1，所以初始化为-1

        stack<int> s; // 存放nums2的下标

        unordered_map<int, int> map; // 用于快速找到num1[i] == nums2[j]

        for (int i = 0; i < nums1.size(); i++)
        {
            map[nums1[i]] = i;
        }

        for (int j = 0; j < nums2.size(); j++)
        {
            while (!s.empty() && nums2[j] > nums2[s.top()])
            {
                // 这里还需要判断nums1里是否有这个元素
                int idx2 = s.top();
                s.pop();
                if (map.count(nums2[idx2]) > 0)
                {
                    int idx1 = map[nums2[idx2]];
                    res[idx1] = nums2[j];
                }
            }

            s.push(j);
        }

        return res;
    }
};
```
