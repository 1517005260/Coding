/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return 0;
        }

        int cnt = 0;

        int curCover = 0;  // 当前的最大覆盖下标
        int nextCover = 0; // 走下一步后的最大覆盖下标

        for (int i = 0; i < nums.size(); i++)
        {
            // 将走未走
            nextCover = max(nextCover, nums[i] + i);

            if (i == curCover)
            {
                // 走到了当前的最大位置，必须走下一步了
                cnt++;
                curCover = nextCover;
                if (curCover >= nums.size() - 1)
                {
                    break;
                }
            }
        }

        return cnt;
    }
};
// @lc code=end
