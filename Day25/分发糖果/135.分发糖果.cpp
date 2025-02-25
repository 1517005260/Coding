/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        // 从前向后遍历的分配结果
        // 需要确保每人至少一颗糖
        vector<int> left(ratings.size(), 1);

        // 从后向前遍历的分配结果
        vector<int> right(ratings.size(), 1);

        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                left[i] = left[i - 1] + 1;
            }
        }

        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                right[i] = right[i + 1] + 1;
            }
        }

        int sum = 0;
        for (int i = 0; i < ratings.size(); i++)
        {
            sum += max(left[i], right[i]);
        }
        return sum;
    }
};
// @lc code=end
