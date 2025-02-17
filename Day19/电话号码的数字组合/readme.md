# 电话号码的数字组合

例题：[leetcode 17 电话号码的数字组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/)

```cpp
class Solution
{
private:
    // 空定义 0，1 是为了让 map[2] 就指向2
    const string map[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz", // 9
    };

    vector<string> _res;
    string s;

    // idx表示给定digits的下标
    void dfs(string &digits, int idx)
    {
        if (idx == digits.size())
        {
            _res.push_back(s);
            return;
        }

        // 取出digits[idx]对应的字母
        string letters = map[digits[idx] - '0'];
        for (int i = 0; i < letters.size(); i++)
        {
            s.push_back(letters[i]);
            dfs(digits, idx + 1);
            s.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (!digits.size())
        {
            return _res;
        }
        dfs(digits, 0);
        return _res;
    }
};
```

理解代码：

假设输入是 "23"：

1. 第一层递归（idx = 0）：

   - `digits[0]` = '2'，对应字母 "abc"
   - 依次尝试 'a', 'b', 'c'

2. 第二层递归（idx = 1）：
   - 当选择 'a' 时，`digits[1]` = '3'，对应字母 "def"
   - 依次尝试 'd', 'e', 'f'，形成 "ad", "ae", "af"
   - 回溯到 'b'，重复过程，形成 "bd", "be", "bf"
   - 回溯到 'c'，重复过程，形成 "cd", "ce", "cf"

这个过程就像一棵树：

```
     root
   /  |  \
  a   b   c
 /|\  |\  |\
d e f d e f ...
```
