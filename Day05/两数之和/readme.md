# 两数之和

例题：[leetcode 01 两数之和](https://leetcode.cn/problems/two-sum/description/)

采用 map 解决，存储`<数组元素，元素下标>`

```cpp
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map; // 存放<元素，下标>
        for (int i = 0; i < nums.size(); i++)
        {
            auto item = map.find(target - nums[i]);
            if (item != map.end())
            {
                // map 中存在 target - nums[i]，即可以配对
                return {item->second, i}; // 返回配对的下标
            }
            else
            {
                // map 中不存在 target - nums[i]，无法配对，但可以将nums[i]加入map以待后续匹配
                map.insert(pair<int, int>(nums[i], i));
            }
        }
        return {};
    }
};
```

时间复杂度: O(n)

空间复杂度: O(n)，来源于 unordered_map
