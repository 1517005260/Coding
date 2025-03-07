# 爬楼梯（进阶版）

例题：[卡码网 57 爬楼梯（进阶版](https://kamacoder.com/problempage.php?pid=1067)

本题就是[组合总和 Ⅳ](../组合总和%20Ⅳ/)的翻译版本

```cpp
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    // target = n, 有 1 ~ m 个楼梯可以选择
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(i >= j){
                dp[i] += dp[i - j];
            }
        }
    }

    cout << dp[n];
    return 0;
}
```
