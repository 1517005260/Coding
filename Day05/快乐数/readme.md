# 快乐数

例题：[leetcode 202 快乐数](https://leetcode.cn/problems/happy-number/description/)

由于题目中说，可能陷入无限循环，那么我们用 set 来记录每次操作后的平方和，如果一个平方和曾经出现在 set 中，那么就是出现了循环，此时直接 break 即可。

```cpp
class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> sums;
        while (true)
        {
            int sum = get_square_sum(n);

            if (sum == 1)
            {
                return true;
            }

            if (sums.find(sum) != sums.end()) // 如果sum曾经出现过
            {
                return false;
            }
            else
            {
                sums.insert(sum);
            }

            n = sum;
        }
    }

private:
    int get_square_sum(int n)
    {
        int sum = 0;
        while (n)
        {
            int a = n % 10; // 末位数
            sum += a * a;
            n /= 10;
        }

        return sum;
    }
};
```

get_square_sum()函数的时间复杂度为 O(log n)，因为数字 n 的位数就是 log n 位。

而对于无限循环，我们可以观察到，“数位平方和”这一操作会迅速地将一个很大的数字转化成更小的数字。例如，假设有一个高达 10 位的整数（大约 21 亿），其各位最大也就是 9，那么一次“各位平方和”最多是 9²×10=810。从第二步开始，数字就会大幅减小到三位数甚至更少范围内。在小范围内（例如最多三位数 810 以下），再进行“数位平方和”最多只能产生有限多的值，之后要么到 1，要么进入一个较小的循环。所以可以认为循环的次数是有限的，即时间复杂度是 O(1)。

总体的时间复杂度为 O(logn)

空间复杂度则来源于使用的 `unordered_set`，用于存储过程中出现过的数位平方和结果，以检测循环。由于数字经过数位平方和的计算后会迅速减小到一个较小范围（例如，10 位数字的最大平方和结果为 810），集合中最多存储的数字种类也是有限的。因此，集合的大小与 n 的位数相关，可以认为空间复杂度为 O(log n)。不过，实际存储的元素数量通常非常少，甚至可以认为是常数级。
