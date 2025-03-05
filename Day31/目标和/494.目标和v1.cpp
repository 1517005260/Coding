/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution
{
private:
    int _cnt = 0;
    // 参数：第idx个数字，目前的总和为sum
    void dfs(vector<int> &nums, int target, int idx, int sum)
    {
        if (idx == nums.size())
        {
            if (sum == target)
            {
                _cnt++;
            }
            return;
        }

        // 下一个数字使用“+”
        dfs(nums, target, idx + 1, sum + nums[idx]);
        // 下一个数字使用“-”
        dfs(nums, target, idx + 1, sum - nums[idx]);
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        dfs(nums, target, 0, 0);
        return _cnt;
    }
};
// @lc code=end
