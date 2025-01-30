# 三数之和

例题：[leetcode 15 三数之和](https://leetcode.cn/problems/3sum/description/)

[两数之和](../../Day05/两数之和/)的升级版。

hash 其实不好解，但是我们可以先尝试一下。思路其实和两数之和差不多，就是找`a+b+c=0`，我们可以找`b=-(a+c)`

两数之和的 hash 法中，我们使用了：`for(a)找b`的思路，那这里其实一样，就是`for(a)for(b)找c`的思路，两重循环，其中`c=-(a+b)`，但是多了去重的步骤。

```cpp
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        // 先对nums排序，方便后续操作
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) // 遍历a
        {
            // 由于我们已经对nums排序过，所以如果nums[i] > 0，后续不可能出现三数之和等于0的情况
            // 同示例2
            if (nums[i] > 0)
            {
                break;
            }

            // 跳过重复的a
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            // 开始找b和c
            unordered_set<int> set_b; // 存放不重复的b
            for (int j = i + 1; j < nums.size(); j++)
            {
                // 去重b=c的情况
                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2])
                {
                    // 跳过相同的三个数，仅保留一个
                    // 例如 -2 0 0 0 2，保留 -2 0(第一个0) 2
                    continue;
                }

                int index = 0 - (nums[i] + nums[j]);
                // 现在需要动态收集b和c
                if (set_b.find(index) != set_b.end())
                {
                    // 如果集合b中有index，即返回 nums[i] index nums[j]
                    res.push_back({nums[i], index, nums[j]}); // 这里index作为b
                    set_b.erase(index);                       // 删除已经用过的b值，避免重复使用
                }
                else
                {
                    // 如果集合b中没有index，那么就吧nums[j]插入set_b作为b，供后续查找
                    set_b.insert(nums[j]);
                }
            }
        }
        return res;
    }
};
```

时间复杂度: O(n²)。空间复杂度: O(n)，来自于额外的 set 开销。

举个例子：nums = [-1, 0, 1, 2, -1, -4]

1. 首先排序：nums = [-4, -1, -1, 0, 1, 2]

2. 第一轮：i = 0，a = nums[0] = -4

   ```
   nums = [-4, -1, -1, 0, 1, 2]
          ^
          i
   ```

   - a = -4
   - set_b = {}

   j = 1:

   ```
   nums = [-4, -1, -1, 0, 1, 2]
          ^    ^
          i    j
   ```

   - nums[j] = -1
   - 寻找的 c = -(-4 + (-1)) = 5
   - set_b 为空，将 nums[j] = -1 加入 set_b
   - 现在 set_b = {-1}

   j = 2:

   ```
   nums = [-4, -1, -1, 0, 1, 2]
          ^        ^
          i        j
   ```

   - nums[j] = -1
   - 寻找的 c = -(-4 + (-1)) = 5
   - set_b 中有 -1，但 5 不在数组中
   - 将 nums[j] = -1 加入 set_b
   - 现在 set_b = {-1}

   j = 3:

   ```
   nums = [-4, -1, -1, 0, 1, 2]
          ^           ^
          i           j
   ```

   - nums[j] = 0
   - 寻找的 c = -(-4 + 0) = 4
   - set_b 中没有 4
   - 将 nums[j] = 0 加入 set_b
   - 现在 set_b = {-1, 0}

   j = 4:

   ```
   nums = [-4, -1, -1, 0, 1, 2]
          ^              ^
          i              j
   ```

   - nums[j] = 1
   - 寻找的 c = -(-4 + 1) = 3
   - set_b 中没有 3
   - 将 nums[j] = 1 加入 set_b
   - 现在 set_b = {-1, 0, 1}

   j = 5:

   ```
   nums = [-4, -1, -1, 0, 1, 2]
          ^                 ^
          i                 j
   ```

   - nums[j] = 2
   - 寻找的 c = -(-4 + 2) = 2
   - set_b 中没有 2
   - 将 nums[j] = 2 加入 set_b
   - 现在 set_b = {-1, 0, 1, 2}

3. 第二轮：i = 1，a = nums[1] = -1

   ```
   nums = [-4, -1, -1, 0, 1, 2]
              ^
              i
   ```

   - a = -1
   - set_b = {}

   j = 2:

   ```
   nums = [-4, -1, -1, 0, 1, 2]
              ^    ^
              i    j
   ```

   - nums[j] = -1
   - 寻找的 c = -(-1 + (-1)) = 2
   - set_b 为空，将 nums[j] = -1 加入 set_b
   - 现在 set_b = {-1}

   j = 3:

   ```
   nums = [-4, -1, -1, 0, 1, 2]
              ^       ^
              i       j
   ```

   - nums[j] = 0
   - 寻找的 c = -(-1 + 0) = 1
   - set_b 中没有 1
   - 将 nums[j] = 0 加入 set_b
   - 现在 set_b = {-1, 0}

   j = 4:

   ```
   nums = [-4, -1, -1, 0, 1, 2]
              ^          ^
              i          j
   ```

   - nums[j] = 1
   - 寻找的 c = -(-1 + 1) = 0
   - 在 set_b 中找到 0
   - 加入解 [-1, 0, 1]
   - 从 set_b 删除 0
   - 现在 set_b = {-1}

   j = 5:

   ```
   nums = [-4, -1, -1, 0, 1, 2]
              ^             ^
              i             j
   ```

   - nums[j] = 2
   - 寻找的 c = -(-1 + 2) = -1
   - 在 set_b 中找到 -1
   - 加入解 [-1, -1, 2]
   - 从 set_b 删除 -1
   - 现在 set_b = {}

4. 第三轮：i = 2

   ```
   nums = [-4, -1, -1, 0, 1, 2]
                  ^
                  i
   ```

   - 因为 nums[2] == nums[1]，跳过此轮

5. 第四轮：i = 3，a = nums[3] = 0

   ```
   nums = [-4, -1, -1, 0, 1, 2]
                      ^
                      i
   ```

   - a = 0
   - set_b = {}

   j = 4:

   ```
   nums = [-4, -1, -1, 0, 1, 2]
                      ^   ^
                      i   j
   ```

   - nums[j] = 1
   - 寻找的 c = -(0 + 1) = -1
   - set_b 为空，将 nums[j] = 1 加入 set_b
   - 现在 set_b = {1}

   j = 5:

   ```
   nums = [-4, -1, -1, 0, 1, 2]
                      ^      ^
                      i      j
   ```

   - nums[j] = 2
   - 寻找的 c = -(0 + 2) = -2
   - set_b 中没有 -2
   - 将 nums[j] = 2 加入 set_b
   - 现在 set_b = {1, 2}

6. 第五轮：i = 4，a = nums[4] = 1
   ```
   nums = [-4, -1, -1, 0, 1, 2]
                         ^
                         i
   ```
   - a = 1 > 0，break 退出循环

最终结果：`[[-1, -1, 2], [-1, 0, 1]]`。

哈希法非常复杂，去重的逻辑很难一次写对，接下来看一种更简单易懂的双指针法。

详见动画原理：

![三数之和](https://code-thinking.cdn.bcebos.com/gifs/15.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.gif)

```cpp
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        // 遍历a
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                break;
            }

            // 跳过重复的a
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            // b = nums[left]; c = nums[right]
            // 如果 a+b+c > 0，说明和大了，right指针需要向左移动
            // 如果 a+b+c < 0，说明和小了，left指针需要向右移动

            while (right > left) // 下标不能重复
            {
                if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else
                {
                    // 找到了符合条件的三元组
                    res.push_back({nums[i], nums[left], nums[right]});

                    // 找到后开始对b和c去重
                    // 如果找到前就开始去重会漏 0 0 0的情况
                    while (right > left && nums[right] == nums[right - 1])
                        right--;
                    while (right > left && nums[left] == nums[left + 1])
                        left++;

                    // 更新right和left，寻找相同a下的不同bc
                    right--;
                    left++;
                }
            }
        }

        return res;
    }
};
```

时间复杂度: O(n²)，空间复杂度: O(1)
