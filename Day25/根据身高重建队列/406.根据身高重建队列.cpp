/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
        {
            // 身高相同，按k升序
            return a[1] < b[1];
        }
        else
        {
            // 按身高降序
            return a[0] > b[0];
        }
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), cmp);

        vector<vector<int>> res;
        for (vector<int> p : people)
        {
            res.insert(res.begin() + p[1], p);
        }

        return res;
    }
};
// @lc code=end
