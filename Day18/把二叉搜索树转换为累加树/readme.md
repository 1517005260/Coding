# 把二叉搜索树转换为累加树

例题：[leetcode 538 把二叉搜索树转换为累加树](https://leetcode.cn/problems/convert-bst-to-greater-tree/description/)

什么是累加树？见下例：

如果输入：`[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]`

那么中序遍历得到：`0 → 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8`

累加过程如下：

```
对于每个节点，我们要计算大于或等于它的所有值的和：

8: 只有它自己 = 8
7: 7 + 8 = 15
6: 6 + 7 + 8 = 21
5: 5 + 6 + 7 + 8 = 26
4: 4 + 5 + 6 + 7 + 8 = 30
3: 3 + 4 + 5 + 6 + 7 + 8 = 33
2: 2 + 3 + 4 + 5 + 6 + 7 + 8 = 35
1: 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 = 36
0: 0 + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 = 36
```

返回：`[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]`

看起来有点复杂，实际上我们将数组倒序即可：例如对于搜索数组 `[2, 5, 13]` ，从后往前累加可以得到`[20, 18, 13]`

由于左中右是升序遍历，所以我们改成右中左就是降序遍历了：

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    int _pre = 0; // 记录前一个节点的值，用于累加
    void dfs(TreeNode *t)
    {
        if (!t)
        {
            return;
        }

        dfs(t->right);

        t->val += _pre;
        _pre = t->val;

        dfs(t->left);
    }

public:
    TreeNode *convertBST(TreeNode *root)
    {
        dfs(root);
        return root;
    }
};
```
