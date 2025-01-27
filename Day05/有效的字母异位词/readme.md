# 有效的字母异位词

例题： [leetcode 242 有效的字母异位词](https://leetcode.cn/problems/valid-anagram/description/)

字母异位词是通过重新排列不同单词或短语的字母而形成的单词或短语，并使用所有原字母一次。

翻译成人话就是，两个给定的单词 s 和 t，必须要有相同数量的相同字母。比如`eat`和`aet`就是字母异位词。

这里我们就可以用数组来模拟 hash 表，开个大小为 26 的数组，记录字母个数：

```cpp
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // 0-a, 1-b, 2-c,... 以此类推
        int alphabet[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            alphabet[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            alphabet[t[i] - 'a']--;
        }

        // 如果是字母异位词，那么alphabet[26]应该全0
        for (int i = 0; i < 26; i++)
        {
            if (alphabet[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};
```

时间复杂度为 O(n)，空间上因为定义是的一个常量大小的辅助数组，所以空间复杂度为 O(1)
