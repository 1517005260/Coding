# 四数之和

例题：[leetcode 18 四数之和](https://leetcode.cn/problems/4sum/description/)

有了[三数之和](../三数之和/)的经验，我们直接采用双指针解决。

不同的是，首先这里 target 不一定为 0，其次需要固定两个数`i,j`，然后再去移动 left 和 right 指针，即在三数之和代码的基础上多了一层循环 j，需要找到`nums[j] + nums[i] + nums[left] + nums[right] = target`。

特别需要注意的是，剪枝操作时，不能草率判断`nums[j] > target `就 break 了，因为如果是`-4 -1 0 0 , target = -5`，就会遗漏这种情况。**target 可以是负数，负数相加是更小的**。

加 long 是为了防止溢出。

```cpp
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        // 多套一层j循环
        for (int j = 0; j < nums.size(); j++)
        {
            // 剪枝处理，需要确保相加的不是负数才能剪枝
            if (nums[j] > target && nums[j] >= 0)
            {
                break;
            }

            // nums[j]去重
            if (j > 0 && nums[j] == nums[j - 1])
            {
                continue;
            }

            // 三数之和的代码：
            for (int i = j + 1; i < nums.size(); i++)
            {
                if (nums[j] + nums[i] > target && nums[j] + nums[i] >= 0)
                {
                    break;
                }

                if (i > j + 1 && nums[i] == nums[i - 1])
                {
                    continue;
                }

                int left = i + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    // 防止溢出
                    long sum = (long)nums[j] + (long)nums[i] + (long)nums[left] + (long)nums[right];
                    if (sum > target)
                    {
                        right--;
                    }
                    else if (sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        res.push_back({nums[j], nums[i], nums[left], nums[right]});

                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        while (left < right && nums[left] == nums[left + 1])
                            left++;

                        right--;
                        left++;
                    }
                }
            }
        }

        return res;
    }
};
```

时间复杂度: O(n³)，空间复杂度: O(1)
