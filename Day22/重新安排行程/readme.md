# 重新安排行程

例题：[leetcode 332 重新安排行程](https://leetcode.cn/problems/reconstruct-itinerary/description/)

相当于给定多条边，要求从点 JFK 开始连线，且点的字典序最小：

我们化简本题题意：给定一个 n 个点 m 条边的图，要求从指定的顶点出发，经过所有的边恰好一次（可以理解为给定起点的「一笔画」问题），使得路径的字典序最小。

```cpp
class Solution
{
private:
    // <出发地点, <到达地点, 机票数>>
    // 其中外层使用 unordered_map，因为我们只需要快速查找从某个机场出发的所有可能航线
    // 内层使用 map，因为 map 会自动按照键（到达地点）的字典序排序
    unordered_map<string, map<string, int>> airlines;

    vector<string> res;

    bool dfs(int tickerNum)
    {
        if (res.size() == tickerNum + 1)
        {
            // 2张机票连接三个地点
            return true;
        }

        /*
        假设现在的情况是：
        res = ["JFK", "SFO"]
        airlines = {
            "SFO": {
                "ATL": 2,  // 从SFO到ATL还有2张票
                "JFK": 1   // 从SFO到JFK还有1张票
            }
        }

        这个循环会依次处理：
        第一次循环：airline = {"ATL", 2}  // 因为ATL字母序在前
        第二次循环：airline = {"JFK", 1}
        */
        // 先看看我们现在在哪个机场（result的最后一个元素）
        // 然后查询从这个机场出发的所有航线（targets[当前机场]）
        // 对每一个可能的目的地，检查是否还有机票可用（target.second > 0）

        string cur = res.back();

        for (auto &airline : airlines[cur])
        {
            if (airline.second > 0)
            {
                airline.second--;
                res.push_back(airline.first);
                if (dfs(tickerNum))
                {
                    return true;
                }
                res.pop_back();
                airline.second++;
            }
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        // 初始化airline
        for (auto &ticket : tickets)
        {
            airlines[ticket[0]][ticket[1]]++;
        }

        res = {"JFK"}; // 从JFK出发
        dfs(tickets.size());
        return res;
    }
};
```

注意这里复杂数据结构需要传引用，否则改的是副本。
