# 实现 strStr()

例题：[leetcode 28 实现 strStr()](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/)

## 字符串匹配算法 KMP

KMP 是前缀函数的一种应用。

1. 前缀函数与**最长匹配真前后缀的长度**

对于字符串：`ATAATA`，它与自身不重复的前缀、后缀分别为：

| 前缀  | 后缀  |
| ----- | ----- |
| ATAAT | TAATA |
| ATAA  | AATA  |
| ATA   | ATA   |
| AT    | TA    |
| A     | A     |
| `\0`  | `\0`  |

**注意：后缀的顺序。比如，`12345`的后缀有`45`而没有`54`。**

其中，找到匹配的前后缀，取长度的最大值，即为`ATA`，他就是最长匹配真前后缀的长度，记为 π

2. 列出字符串的所有非空前缀，以及这个前缀对应的 π 值

| i    | 0   | 1   | 2   | 3    | 4     | 5      |
| ---- | --- | --- | --- | ---- | ----- | ------ |
| 前缀 | A   | AT  | ATA | ATAA | ATAAT | ATAATA |
| π    | 0   | 0   | 1   | 1    | 2     | 3      |

π[ i ] = 字符串的第 i 个前缀的最长匹配真前后缀的长度，即**对应长度的前缀等于后缀**（前缀函数）。

3. 有了前置定义，我们开始进行匹配

- 模式串：`ATAATA`
- 主串：`AGCATAATAATTAA`

需要在主串中找到模式串。

肉眼匹配结果是：`AGC | ATAATA | ATTAA`

4. 计算机的方法

首先，将模式串和主串用特殊符号连接在一起，即：`ATAATA#AGCATAATAATTAA`

然后，计算新字符串的 π 数组，如下：

| 合并串 | A   | T   | A   | A   | T   | A   | #   | A   | G   | C   | A   | T   | A   | A   | T   | A   | A   | T   | T   | A   | A   |
| ------ | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| π      | 0   | 0   | 1   | 1   | 2   | 3   | 0   | 1   | 0   | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 4   | 5   | 0   | 1   | 1   |

如果有`π[i] == 模式串长度`，那么我们就找到了匹配结果。因为合并串长度为 π[ i ]的前缀就是模式串。

而在本例中，我们会找到`π[i] == 6`，此时的情况如下:

```
| ATAATA | #AGC | ATAATA |
```

所以，在合并串的子串 `ATAATA#AGCATAATA` 中，我们找到了模式串与主串匹配的结果，这里模式串是前缀，主串匹配的结果是后缀。

5. 有了以上的结论，现在的目标就是快速计算出 π[ i ]

```
○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○
                                      ↑
                                      πi
```

假设从 π0 ~ πi-1 已经计算完成，由 π 函数定义，对应长度的前缀等于后缀，那么有：两端长度为 πi-1 的字符串是相等的：

```
○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○     ○
                                    ↑     ↑
                                    πi-1  πi
-----------              ------------
   πi-1=len                   πi-1
            ↑
            len
```

由上图，len 下标是前缀长度 πi-1 的后一位。如果它指向的字符等于第 i 位字符，那么有：

```
○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○     ○
                                    ↑     ↑
                                    πi-1  πi
--------------             -----------------
πi-1  + 1 = πi                     πi
```

当然更多情况两者是不相等的，那么此时我们需要依次递减前缀和后缀的长度，如下所示找到相同的前缀和后缀

```
○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○     ○
                                    ↑     ↑
                                    πi-1  πi
------                         ------
 π'i-1                          π'i-1
```

翻译为代码为：

```cpp
vector<int> pi(str.size());
for (int i = 1; i < str.size(); i++) {
   int len = pi[i-1];
   while (len != 0 && str[i] != str[len]) {
       len = pi_next(i - 1);
   }
   if (str[i] == str[len]) {
       pi[i] = len + 1;
   }
}
```

6. 现在的问题是：pi_next(i - 1)是什么？

```
○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○     ○
          ↑                         ↑     ↑
         len-1                      πi-1  πi
-----------              ------------
   πi-1                     πi-1
            ↑
            len
```

我们考察这样三个区间：

```
○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○ ○    ○
xxx      yyy                        zzz    ↑
-----------                    --------    i
    πi-1                        πi-1
```

- 因为 πi-1 段的前后缀是相等的，所以 y 区间等于 z 区间
- 我们再令 π'i-1 就是 xxx 区间的长度，那么有 x 遇见等于 z 区间

所以，x 区间等于 y 区间

我们要求的是最长的 π'i-1，即 0~len-1 这段区间的最长匹配真前后缀的长度，即 π len-1

所以有：

```cpp
vector<int> pi(str.size());
for (int i = 1; i < str.size(); i++) {
   int len = pi[i-1];
   while (len != 0 && str[i] != str[len]) {
       len = pi[len-1];
   }
   if (str[i] == str[len]) {
       pi[i] = len + 1;
   }
}
```

## 题目

本题直接套模板即可

```cpp
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        // haystack 是主串
        // needle 是模式串
        int pattern_len = needle.size();

        // 合并串
        string str = needle + '#' + haystack;
        // π 数组
        vector<int> pi(str.size());
        for (int i = 1; i < str.size(); i++)
        {
            int len = pi[i - 1];
            while (len != 0 && str[i] != str[len])
            {
                len = pi[len - 1];
            }
            if (str[i] == str[len])
            {
                pi[i] = len + 1;

                // 匹配成功
                if (pi[i] == pattern_len)
                {
                    return i - pattern_len * 2; // i是合并串里的下标，还要注意减掉合并串中的模式串前缀。
                }
            }
        }
        return -1;
    }
};
```

时间复杂度 O(n)
