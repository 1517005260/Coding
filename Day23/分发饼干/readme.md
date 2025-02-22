# 分发饼干

例题：[leetcode 455 分发饼干](https://leetcode.cn/problems/assign-cookies/description/)

为了满足更多的小孩，就不要造成饼干尺寸的浪费。

大尺寸的饼干既可以满足胃口大的孩子也可以满足胃口小的孩子，那么就应该优先满足胃口大的。

这里的局部最优就是大饼干喂给胃口大的，充分利用饼干尺寸喂饱一个，全局最优就是喂饱尽可能多的小孩。

```cpp
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int cnt = 0;

        int s_idx = s.size() - 1;
        // 遍历胃口
        for (int g_idx = g.size() - 1; g_idx >= 0; g_idx--)
        {
            if (s_idx >= 0 && s[s_idx] >= g[g_idx])
            {
                // 发现可以满足胃口
                cnt++;
                s_idx--;
            }
        }

        return cnt;
    }
};
```
