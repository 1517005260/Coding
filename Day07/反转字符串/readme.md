# 反转字符串

例题：[leetcode 344 反转字符串](https://leetcode.cn/problems/reverse-string/description/)

库函数`reverse()`的实现

```cpp
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        // 双指针解决
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }
};
```
