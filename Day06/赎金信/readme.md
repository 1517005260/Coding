# 赎金信

例题： [leetcode 383 赎金信](https://leetcode.cn/problems/ransom-note/description/)

思路同[字母异位词](../../Day05/有效的字母异位词/)

这里多了一个条件，就是 magazine 中的每个字符只能在 ransomNote 中使用一次。所以我们还要对字符串长度做额外的判断。

```cpp
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int alphabet[26] = {0};
        if (ransomNote.size() > magazine.size())
        {
            return false;
        }

        for (int i = 0; i < magazine.size(); i++)
        {
            alphabet[magazine[i] - 'a']++;
        }

        for (int i = 0; i < ransomNote.size(); i++)
        {
            alphabet[ransomNote[i] - 'a']--;
            // ransomNote可以不用magazine中的字母
            // 所以alphabet的元素可以大于等于0，但不能小于0
            if (alphabet[ransomNote[i] - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};
```
