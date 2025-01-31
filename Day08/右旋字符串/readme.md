# 右旋字符串

例题： [卡码网 55 右旋字符串](https://kamacoder.com/problempage.php?pid=1065)

总体思路：

1. 反转整个字符串

2. 以 k 为界反转子串

例如：

`abcdefg`, k=2 -> `abcde | fg` -> `gf | edcba` -> `fg | abcde`

```cpp
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int k;
    cin >> k;
    string s;
    cin >> s;

    // 1. 反转字符串
    reverse(s.begin(), s.end());

    // 2. 以k为界反转字串
    reverse(s.begin(), s.begin() + k);
    reverse(s.begin() + k, s.end());

    cout << s;
}
```
