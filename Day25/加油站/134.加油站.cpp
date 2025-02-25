/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int startIdx = 0; // 起始位置
        int curSum = 0;   // 当前油量盈亏
        int totalSum = 0; // 总油量盈亏

        for (int i = 0; i < gas.size(); i++)
        {
            int rest = gas[i] - cost[i];

            curSum += rest;
            totalSum += rest;

            if (curSum < 0)
            {
                // 当前油量为亏，说明这不是可行解，需要从i+1出发再试
                startIdx = i + 1;
                curSum = 0;
            }
        }

        if (totalSum < 0)
        {
            // 总油量盈亏为负
            return -1;
        }

        return startIdx;
    }
};
// @lc code=end
