/*
 * @lc app=leetcode.cn id=647 lang=cpp
 * @lcpr version=30103
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // dp
        int cnt = 0;
        // 区间为[i, j]
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i <= 1)
                    {
                        // 对应于初始化的情况
                        // 1. i = j ，显然为true
                        // 2. i = j-1，由于在s[i] == s[j]分支里，所以为true
                        dp[i][j] = true;
                    }
                    else
                    {
                        // 在s[i] == s[j]分支里，所以只要看子串即可
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if (dp[i][j])
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abc"\n
// @lcpr case=end

// @lcpr case=start
// "aaa"\n
// @lcpr case=end

 */
