# 划分字母区间

例题：[leetcode 763 划分字母区间](https://leetcode.cn/problems/partition-labels/description/)

将字符串划分为尽可能多的片段，同一个字母最多出现在一个片段中。

![png](https://code-thinking-1253855093.file.myqcloud.com/pics/20201222191924417.png)

原理如图，我们需要找到每个字母出现的最大下标，然后按照该下标划分字符串即可。

```cpp
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int map[26] = {0}; // 统计26个字母出现在的最后位置
        for (int i = 0; i < s.size(); i++)
        {
            map[s[i] - 'a'] = i;
        }

        vector<int> res;

        int left = 0;  // 左边界
        int right = 0; // 右边界
        for (int i = 0; i < s.size(); i++)
        {
            // 更新最大右边界
            right = max(right, map[s[i] - 'a']);

            // 贪心，尽可能早地结束区间，使得分段更多
            if (i == right)
            {
                res.push_back(right - left + 1);
                // 更新左边界
                left = i + 1;
            }
        }

        return res;
    }
};
```
