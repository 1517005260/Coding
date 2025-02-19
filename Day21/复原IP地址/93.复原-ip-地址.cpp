/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution
{
private:
    vector<string> _res;

    // 判断字符串s的 [start, end] 区间是否符合ip地址规范
    bool is_valid(string &s, int start, int end)
    {
        if (start > end)
        {
            return false;
        }

        // 不能有前导0，即0开头，只能单个0，后面不能跟东西
        if (s[start] == '0' && start != end)
        {
            return false;
        }

        int num = 0; // 将字符串转成数字
        for (int i = start; i <= end; i++)
        {
            if (s[i] < '0' || s[i] > '9')
            {
                return false;
            }

            num = num * 10 + (s[i] - '0');
            if (num > 255)
            {
                return false;
            }
        }
        return true;
    }

    void dfs(string s, int startIdx, int sum)
    {
        if (sum == 3)
        {
            // 被分成了四段，即三个 .
            if (is_valid(s, startIdx, s.size() - 1))
            {
                _res.push_back(s);
            }
            return;
        }

        for (int i = startIdx; i < s.size(); i++)
        {
            // 判断 [startIdx, i] 区间的数字是否合法
            if (is_valid(s, startIdx, i))
            {
                // 如果合法，那么是一种分割方式，可以在i后面加个 .
                s.insert(s.begin() + i + 1, '.');
                // . 的数量+1
                sum++;
                // 之后的startIdx就是i+2的位置，i+1是 .
                dfs(s, i + 2, sum);
                sum--;
                s.erase(s.begin() + i + 1);
            }
            else
            {
                // 不合法直接结束
                break;
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        // 剪枝
        if (s.size() < 4 || s.size() > 12)
        {
            return _res;
        }
        dfs(s, 0, 0);
        return _res;
    }
};
// @lc code=end
