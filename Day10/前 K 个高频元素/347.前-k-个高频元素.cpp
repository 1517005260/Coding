/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // 使用map来维护nums[i]出现的次数
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }

        // 创建小根堆
        priority_queue<
            pair<int, int>,                                // 堆的数据类型，即map
            vector<pair<int, int>>,                        // 底层用数组实现堆
            function<bool(pair<int, int>, pair<int, int>)> // 自定义比较函数
            >
            q // 优先队列名
            (
                // 匿名函数实现自定义比较逻辑
                // []为空不捕获任何外部变量
                [](const pair<int, int> &l, const pair<int, int> &r)
                {
                    return l.second > r.second;
                });

        // 维护大小为k的小根堆
        for (const auto &[num, freq] : map)
        {
            q.push({num, freq});
            if (q.size() > k)
            {
                q.pop();
            }
        }

        // 返回结果
        vector<int> res;
        for (int i = k - 1; i >= 0; i--)
        {
            res.push_back(q.top().first);
            q.pop();
        }

        return res;
    }
};
// @lc code=end
