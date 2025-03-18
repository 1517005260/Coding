# 回文子串

例题：[leetcode 647 回文子串](https://leetcode.cn/problems/palindromic-substrings/description/)

注意单个字母也是回文串。

1. dp 数组的定义：

这里注意，绝大多数题目都是题目要求什么，我们根据要求去直接定义 dp 数组的含义即可。但是这里有回文串的特殊性，不能定义为下标 i 结尾的字符串有`dp[i]`个回文串：

![png](https://code-thinking-1253855093.file.myqcloud.com/pics/20230102170752.png)

我们在判断字符串 S 是否是回文，那么如果我们知道 `s[1]，s[2]，s[3]`（bab） 这个子串是回文的，那么只需要比较 `s[0]`和 `s[4]`这两个元素是否相同，如果相同的话，这个字符串 s 就是回文串。

那么此时我们是不是能找到一种递归关系，也就是判断一个子字符串（字符串下标范围`[i,j]`）是否回文，依赖于，子字符串（下标范围`[i + 1, j - 1]`） 是否是回文。

所以为了明确这种递归关系，我们的 dp 数组是要定义成二维 dp 数组。

布尔类型的 `dp[i][j]`：表示区间范围`[i,j]`（左闭右闭）的子串是否是回文子串，如果是则 `dp[i][j]`为 true，否则为 false。

2. 递推公式

如果`s[i] == s[j]`，那么我们判断其子字符串，即`[i+1, j-1]`，如果它是回文串，即`dp[i+1][j-1] = true`，那么`dp[i][j] = true`。

```
dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1]
```

3. 遍历顺序：

由于`dp[i][j]`依赖于 i+1 和 j-1，所以 i 要从大到小遍历，j 要从小到大遍历

4. 初始化：

```
// 只有一个字母时
dp[i][i] = true;

// 两个字母时，只要比较它们是否相等即可
dp[i][i + 1] = (s[i] == s[i + 1]);
```

```cpp
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
```
