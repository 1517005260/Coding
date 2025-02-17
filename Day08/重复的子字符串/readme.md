# 重复的子字符串

例题：[leetcode 459 重复的子字符串](https://leetcode.cn/problems/repeated-substring-pattern/description/)

除了常规的套 pi 模板，接下来需要证明：

# 重复子串模式的数学证明

## 1. 定理描述

对于长度为 n 的字符串 s,其前缀函数最后一个值记为 L = π[n-1]。
字符串 s 可以由某个子串重复多次构成的充要条件是:

```
L != 0 且 n % (n - L) = 0
```

## 2. 必要性证明

### 2.1 假设条件

假设字符串 s 可以由某个长度为 p 的子串 t 重复 k 次构成(k > 1)。
即:s = t·t·...·t(k 个 t)

### 2.2 推导过程

1. 由假设可知:

   - 字符串总长度 n = k·p
   - 子串 t 重复了 k 次

2. 考察字符串 s 的前缀和后缀:

   ```
   s = t·t·...·t
   前缀:t·t·...·t (k-1个t)
   后缀:t·t·...·t (k-1个t)
   ```

3. 根据前缀函数的定义:

   - π[n-1] 表示最长相等真前后缀的长度
   - 显然,(k-1)个 t 构成的前缀等于后缀
   - 所以 L = π[n-1] = (k-1)·p

4. 因此:

   - n - L = k·p - (k-1)·p = p
   - 即:n - L 等于子串 t 的长度

5. 由此可得:

   - n = k·p = k·(n - L)
   - 所以 n % (n - L) = 0

6. 另外,由 k > 1 可知:
   - L = (k-1)·p > 0

因此,必要性得证。

## 3. 充分性证明

### 3.1 假设条件

假设对于字符串 s,有:

- L = π[n-1] ≠ 0
- n % (n - L) = 0

### 3.2 推导过程

1. 令 p = n - L,k = n/p
   由于 n % p = 0,所以 k 是整数

2. 根据前缀函数的定义:

   - s[0:L-1] = s[n-L:n-1]
   - 即长度为 L 的前缀等于长度为 L 的后缀

3. 由此可以推出:

   ```
   s = t·t·...·t
   其中 t = s[0:p-1],重复了 k 次
   ```

4. 证明这样构造的确实是原字符串:

   - 由于前后缀相等
   - s[0:p-1] = s[p:2p-1] = ... = s[(k-1)p:kp-1]
   - 这正好覆盖了整个字符串

5. 另外,由于 L ≠ 0 且 L < n
   所以 k > 1,满足重复子串的要求

因此,充分性得证。

## 4. 结论

通过以上证明,我们可以确定:
一个字符串能否由某个子串重复多次构成
⟺
L ≠ 0 且 n % (n - L) = 0

这就是代码中判断条件的理论基础。

## 5. 举例验证

以字符串 "abcabcabc" 为例:

```
n = 9
L = π[8] = 6
n - L = 3
9 % 3 = 0
```

确实可以由 "abc" 重复 3 次构成。

代码实现：

```cpp
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        // 首先根据模板求解pi数组
        vector<int> pi(s.size());
        for (int i = 1; i < s.size(); i++)
        {
            int len = pi[i - 1];
            while (len != 0 && s[i] != s[len])
            {
                len = pi[len - 1];
            }
            if (s[i] == s[len])
            {
                pi[i] = len + 1;
            }
        }

        int n = s.size();
        int L = pi[n - 1];
        if (L != 0 && n % (n - L) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
```
