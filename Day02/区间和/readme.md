# 区间和

例题：[卡码网 59 区间和](https://kamacoder.com/problempage.php?pid=1070)

前缀和：

```cpp
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    vector<int> sums(n, 0);  // 前缀和数组
    int sum = 0;

    for(int i = 0; i < n; i++){
        cin >> nums[i];
        sum += nums[i];
        sums[i] = sum;
    }

    int a, b;
    while(cin >> a >> b){
        cout << sums[b] - sums[a - 1] << endl;  // 注意是 a - 1，否则会少算 nums[a]
    }
}
```
