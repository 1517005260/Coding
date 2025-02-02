/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution
{
private:
    deque<int> q; // 使用双端队列来模拟单调队列

    void pop(int val)
    {
        // pop 掉队头元素val
        if (!q.empty() && q.front() == val)
        {
            q.pop_front();
        }
    }

    void push(int val)
    {
        // 加入元素val
        // 如果加入的元素是比前面的大，那么前面的元素pop
        while (!q.empty() && val > q.back())
        {
            q.pop_back();
        }
        q.push_back(val);
    }

    int get_max()
    {
        // 返回当前滑动窗口的最大值，即队头
        return q.front();
    }

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;

        // 初始化滑动窗口
        for (int i = 0; i < k; i++)
        {
            push(nums[i]);
        }
        res.push_back(get_max());

        // 移动滑动窗口
        for (int i = k; i < nums.size(); i++)
        {
            pop(nums[i - k]); // nums[i-k] 超过了滑动窗口的限制
            push(nums[i]);
            res.push_back(get_max());
        }

        return res;
    }
};
// @lc code=end
