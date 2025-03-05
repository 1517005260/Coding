# 不同的二叉搜索树

例题：[leetcode 96 不同的二叉搜索树](https://leetcode.cn/problems/unique-binary-search-trees/description/)

本题的不同形状可以先手动推一下：

![png](https://code-thinking-1253855093.file.myqcloud.com/pics/20210107093106367.png)

![png](https://code-thinking-1253855093.file.myqcloud.com/pics/20210107093129889.png)

尝试推出规律：

![png](https://code-thinking-1253855093.file.myqcloud.com/pics/20210107093226241.png)

`dp[3]`，就是 元素 1 为头结点搜索树的数量 + 元素 2 为头结点搜索树的数量 + 元素 3 为头结点搜索树的数量

元素 1 为头结点搜索树的数量 = 右子树有 2 个元素的搜索树数量 \* 左子树有 0 个元素的搜索树数量

元素 2 为头结点搜索树的数量 = 右子树有 1 个元素的搜索树数量 \* 左子树有 1 个元素的搜索树数量

元素 3 为头结点搜索树的数量 = 右子树有 0 个元素的搜索树数量 \* 左子树有 2 个元素的搜索树数量

有 2 个元素的搜索树数量就是` dp[2]`。

有 1 个元素的搜索树数量就是 `dp[1]`。

有 0 个元素的搜索树数量就是 `dp[0]`。

所以 `dp[3] = dp[2] * dp[0] + dp[1] * dp[1] + dp[0] * dp[2]`

1. dp 数组的含义：i 个不同元素节点组成的二叉搜索树的个数为`dp[i]`

2. 递推公式：

`dp[i] += dp[以j为头结点左子树节点数量] * dp[以j为头结点右子树节点数量]`

j 相当于是头结点的元素，从 1 遍历到 i 为止。

所以递推公式：`dp[i] += dp[j - 1] * dp[i - j]`; j-1 为 j 为头结点左子树节点数量，i-j 为以 j 为头结点右子树节点数量（二叉搜索树的性质：左小右大）

3. 初始化：`dp[0]=1`，空树也是二叉搜索树

4. 遍历顺序：i，j 从前向后遍历即可

```cpp
class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
};
```
