# 滑动窗口最大值

例题：[leetcode 239 滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum/description/)

使用单调队列（Monotonic queue）的经典题目。

题意即为在给定的 k 范围内找出最大的元素，这里我们考虑单调性，

```
每次遇到新元素 nums[i] 时，将它插入到队列中，并移除队列中比它小的元素，以保证队列中的元素始终是单调递减的。

当窗口滑动时，弹出超出窗口范围的元素，保持队列中的最大元素始终为窗口的最大值。
```

例如，对于：`nums = [1,3,-1,-3,5,3,6,7] , k = 3`

| 步骤 | 当前元素 `nums[i]` | 队列状态                            | 当前窗口最大值 |
| ---- | ------------------ | ----------------------------------- | -------------- |
| 1    | 1                  | `[1]`                               |                |
| 2    | 3                  | `[3]`（这里 pop 掉比 3 小的）       | 3              |
| 3    | -1                 | `[3, -1]`                           | 3              |
| 4    | -3                 | `[3, -1, -3]`                       | 3              |
| 5    | 5                  | `[5]` （这里 pop 掉超过窗口大小的） | 5              |
| 6    | 3                  | `[5, 3]`                            | 5              |
| 7    | 6                  | `[6]`                               | 6              |
| 8    | 7                  | `[7]`                               | 7              |

动画图解：

![gif](https://code-thinking.cdn.bcebos.com/gifs/239.%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC-2.gif)

```cpp
class Solution
{
private:
    deque<int> q; // 使用双端队列来模拟单调队列

    void pop(int val)
    {
        // pop 掉队头元素val
        if (!q.empty() && q.front() == val)
        {
            q.pop_front();
        }
    }

    void push(int val)
    {
        // 加入元素val
        // 如果加入的元素是比前面的大，那么前面的元素pop
        while (!q.empty() && val > q.back())
        {
            q.pop_back();
        }
        q.push_back(val);
    }

    int get_max()
    {
        // 返回当前滑动窗口的最大值，即队头
        return q.front();
    }

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;

        // 初始化滑动窗口
        for (int i = 0; i < k; i++)
        {
            push(nums[i]);
        }
        res.push_back(get_max());

        // 移动滑动窗口
        for (int i = k; i < nums.size(); i++)
        {
            pop(nums[i - k]); // nums[i-k] 超过了滑动窗口的限制
            push(nums[i]);
            res.push_back(get_max());
        }

        return res;
    }
};
```

时间复杂度: O(n)，空间复杂度: O(k)
