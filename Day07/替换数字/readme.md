# 替换数字

例题：[卡码网 54 替换数字](https://kamacoder.com/problempage.php?pid=1064)

使用双指针解决

**很多数组填充类的问题，其做法都是先预先给数组扩容带填充后的大小，然后在从后向前进行操作**

思路：

![img](https://code-thinking-1253855093.file.myqcloud.com/pics/20231030173058.png)

```cpp
#include<iostream>

using namespace std;

int main(){
    string s;
    while(cin >> s){
        int cnt = 0;  // 统计数字的个数
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                cnt++;
            }
        }
        int old_index = s.size() - 1;
        s.resize(s.size() + cnt * 5);  // 扩充字符串的空间
        int new_index = s.size() - 1;

        // 开始从后向前替换，避免数组的整体移动
        while(old_index >= 0){
            // 遍历旧数组
            if(s[old_index] >= '0' && s[old_index] <= '9'){
                // 填充新数组
                s[new_index--] = 'r';
                s[new_index--] = 'e';
                s[new_index--] = 'b';
                s[new_index--] = 'm';
                s[new_index--] = 'u';
                s[new_index--] = 'n';
            }else{
                s[new_index--] = s[old_index];
            }
            old_index--;
        }
        cout<< s << endl;
    }
}
```

时间复杂度：O(n)，空间复杂度：O(1)
