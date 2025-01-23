# 开发商购买土地

例题：[卡码网 44 开发商购买土地](https://kamacoder.com/problempage.php?pid=1044)

前缀和的应用：

```cpp
#include<iostream>
#include<vector>
#include<climits>  // INT32_MAX

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> area (n, vector<int>(m, 0));

    int sum = 0;  // 土地总价值

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            cin >> area[i][j];
            sum += area[i][j];    // 计算土地总价值
        }
    }

    //  题意即为只能横向或者纵向切一刀，切出来的两部分价值差最小
    // 这里分别统计行和列的前缀和

    vector<int> sum_i (n, 0);  // 行前缀和
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            sum_i[i] += area[i][j];
        }
    }

    vector<int> sum_j (m, 0);  // 列前缀和
    for(int j = 0; j < m; j ++){
        for(int i = 0; i < n; i ++){
            sum_j[j] += area[i][j];
        }
    }

    //  现在我们有了行和列的前缀和，尝试进行切分

    // 首先是横着切，那么应该算行前缀和
    int res = INT32_MAX;
    int area_above = 0;    // 横着切，上半部分的价值
    for(int i = 0; i < n; i ++){
        area_above += sum_i[i];
        int area_below = sum - area_above;   // 横着切，下半部分的价值
        res = min(res, abs(area_above - area_below));
    }

    // 然后尝试竖着切，思路同上
    int area_left = 0;
    for(int j = 0; j < m; j ++){
        area_left += sum_j[j];
        int area_right = sum - area_left;
        res = min(res, abs(area_left - area_right));
    }

    cout << res;
}
```

由于需要操作矩阵，所以时间复杂度为 O(n²)（O(n \* m)）
