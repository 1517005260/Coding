/*
 * @lc app=leetcode.cn id=739 lang=cpp
 * @lcpr version=30104
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> res(temperatures.size(), 0);

        stack<int> s;

        for (int i = 0; i < temperatures.size(); i++)
        {
            // 如果栈非空，且栈顶下标对应的温度，小于右边新来的，满足条件
            while (!s.empty() && temperatures[s.top()] < temperatures[i])
            {
                int idx = s.top();
                s.pop();
                res[idx] = i - idx;
            }

            s.push(i);
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [73,74,75,71,69,72,76,73]\n
// @lcpr case=end

// @lcpr case=start
// [30,40,50,60]\n
// @lcpr case=end

// @lcpr case=start
// [30,60,90]\n
// @lcpr case=end

 */
