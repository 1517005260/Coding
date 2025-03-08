# 单词拆分

例题：[leetcode 139 单词拆分](https://leetcode.cn/problems/word-break/description/)

爬楼梯字符串版，现在手上的步数是子字符串，我们需要爬到楼顶，即母串 s。

1. `dp[i]`定义：字符串 `s[i]` 是否可以被 wordDict 里的字串拼接而成。`dp[s.size()]`就是结果。

2. 递推公式：

如果`dp[j]`为 true，那么如果字串`s[i-j]`在 wordDict 里，我们就可以选择该字串，故而`dp[i] = true`

3. 初始化：显然一开始 dp 数组应该全 false

`dp[0] = true`，空串必须为 true，否则递推公式无法使用。而且题目数据保证 s.length()一定大于等于 1。

4. 遍历顺序：先 i 后 j

```cpp
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
```
