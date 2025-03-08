/*
 * @lc app=leetcode.cn id=139 lang=cpp
 * @lcpr version=30100
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        vector<bool> dp(n + 1, false);

        dp[0] = true;

        // 用于在O(1)的复杂度查找 s[j:i] 是否在wordDict中
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        for (int i = 1; i <= n; i++)
        {
            // j 要从0开始，否则dp[j]一直是false
            for (int j = 0; j < i; j++)
            {
                if (dp[j] == true && wordSet.find(s.substr(j, i - j)) != wordSet.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

/*
// @lcpr case=start
// "leetcode"\n["leet", "code"]\n
// @lcpr case=end

// @lcpr case=start
// "applepenapple"\n["apple", "pen"]\n
// @lcpr case=end

// @lcpr case=start
// "catsandog"\n["cats", "dog", "sand", "and", "cat"]\n
// @lcpr case=end

 */
