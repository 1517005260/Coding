/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> res;
    vector<int> tmp;

    // nums.length最大为6
    int used[6] = {0};

    void dfs(vector<int> &nums)
    {
        if (tmp.size() == nums.size())
        {
            // 所有元素都用过了，说明找到了一组全排列
            res.push_back(tmp);
            return;
        }

        // 排列问题不需要startIdx，因为 123 和 213 是两种排列
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] == 1)
            {
                continue;
            }

            used[i] = 1;
            tmp.push_back(nums[i]);
            dfs(nums);
            tmp.pop_back();
            used[i] = 0;
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        dfs(nums);
        return res;
    }
};
// @lc code=end
