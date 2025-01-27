/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
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
// @lc code=end
