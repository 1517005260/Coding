/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution
{
    // sort函数要求自定义比较函数为static
    static bool cmp(int a, int b)
    {
        return abs(a) > abs(b); // 按绝对值降序排列
    }

public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(), cmp);

        for (int i = 0; i < nums.size(); i++)
        {
            // 消耗k
            if (nums[i] < 0 && k > 0)
            {
                k--;
                nums[i] = -nums[i];
            }
        }

        // 如果k还有剩余
        // 如果是偶数，则对最后一个数施加符号相当于没做
        // 如果是奇数，那么就相当于加一次负号
        if (k % 2 == 1)
        {
            nums.back() = -nums.back();
        }

        int sum = 0;
        for (int num : nums)
        {
            sum += num;
        }
        return sum;
    }
};
// @lc code=end
