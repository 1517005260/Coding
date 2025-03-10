/*
 * @lc app=leetcode.cn id=121 lang=cpp
 * @lcpr version=30100
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1)
        {
            return 0;
        }

        int noStock = 0;
        int hasStock = -prices[0];

        for (int i = 1; i < n; i++)
        {
            noStock = max(noStock, hasStock + prices[i]);
            hasStock = max(hasStock, -prices[i]);
        }

        return noStock;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */
