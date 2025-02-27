# 单调递增的数字

例题：[leetcode 738 单调递增的数字](https://leetcode.cn/problems/monotone-increasing-digits/description/)

例如，对于数字 97，我们进行判断：

- `nums[i-1]` > `nums[i]`，说明不是单调递增的
- 此时需要令`nums[i-1] --` ， `nums[i]` = 9（贪心，因为要尽可能大）
- 即`89`

```cpp
class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        string num = to_string(n);

        int idx = num.size(); // 从idx开始，后面的数字都应该变成9
        for (int i = num.size() - 1; i > 0; i--)
        {
            if (num[i] < num[i - 1])
            {
                num[i - 1]--;
                idx = i;
            }
        }

        // 全变成9
        for (int i = idx; i < num.size(); i++)
        {
            num[i] = '9';
        }

        return stoi(num);
    }
};
```

举例：

```
对于332：

i = 2, => 322, idx = 2
i = 1, => 222, idx = 1

结束遍历，现在从idx=1的地方全变成9
=> 299
```
