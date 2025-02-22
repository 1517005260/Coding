/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return nums.size();
        }

        // 我们需要记录相邻的差值
        int curDiff = 0;
        int preDiff = 0;

        // 初始长度为1，因为第一个数字一定是序列的一部分
        int cnt = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            curDiff = nums[i] - nums[i - 1];

            // 贪心地找到摆动的序列
            // 如果当前差值和前一个差值满足摆动条件
            // (之前是上升，现在是下降) 或 (之前是下降，现在是上升) 或 (是第一段)
            if (curDiff > 0 && preDiff <= 0 || curDiff < 0 && preDiff >= 0)
            {
                cnt++;
                preDiff = curDiff;
            }
        }

        return cnt;
    }
};
// @lc code=end
