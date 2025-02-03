# 二叉树的迭代遍历

递归的底层实际上就是用栈实现的，所以我们使用栈来模拟简单递归。

1. [leetcode 144 二叉树的前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal/description/)

先加入根节点，然后弹出根节点。之后先加入右儿子，再加入左儿子（因为栈先进后出，这样才能达成根左右的顺序）

动画模拟：

![gif](https://code-thinking.cdn.bcebos.com/gifs/%E4%BA%8C%E5%8F%89%E6%A0%91%E5%89%8D%E5%BA%8F%E9%81%8D%E5%8E%86%EF%BC%88%E8%BF%AD%E4%BB%A3%E6%B3%95%EF%BC%89.gif)

```cpp
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
        {
            return res;
        }

        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *t = s.top();
            s.pop();
            res.push_back(t->val);
            if (t->right) // 注意需要非空判断，否则会push到null
                s.push(t->right);
            if (t->left)
                s.push(t->left);
        }

        return res;
    }
};
```

时间复杂度：O(n)，其中 n 是二叉树的节点数。每一个节点恰好被遍历一次。

空间复杂度：O(n)，为迭代过程中显式栈的开销，平均情况下为 O(logn)，最坏情况下树呈现链状，为 O(n)。

2. [leetcode 145 二叉树的后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal/description/)

我们进行前序遍历的复用。

本来前序遍历的结果是`中左右`，现在进行代码上的调整，变成`中右左`。最后对 res 数组进行反转，得到`左右中`.

```cpp
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
        {
            return res;
        }

        stack<TreeNode *> s;
        s.push(root);

        while (!s.empty())
        {
            TreeNode *t = s.top();
            s.pop();
            res.push_back(t->val);

            if (t->left)
            {
                s.push(t->left);
            }
            if (t->right)
            {
                s.push(t->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

3. [leetcode 94 二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/description/)

中序遍历和前序遍历不一样，因为前序是访问即处理（处理即加入到 res 中），中序需要我们先依靠 root 节点 dfs 到最左边的节点，再从该节点向上处理。

所以，我们需要一个辅助指针来帮助我们访问节点，分开处理栈顶节点。

![gif](https://code-thinking.cdn.bcebos.com/gifs/%E4%BA%8C%E5%8F%89%E6%A0%91%E4%B8%AD%E5%BA%8F%E9%81%8D%E5%8E%86%EF%BC%88%E8%BF%AD%E4%BB%A3%E6%B3%95%EF%BC%89.gif)

"入栈"代表了向左走的过程，而"出栈"代表了处理节点并转向右子树的过程。当处理完一个节点后，代码会尝试访问其右子树。这保证了"左-中-右"的访问顺序。

```cpp
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *now = root; // 辅助指针

        while (now != nullptr || !s.empty())
        {
            if (now != nullptr)
            {
                s.push(now);
                now = now->left; // 一路向左
            }
            else
            {
                // now == nullptr
                TreeNode *t = s.top();
                s.pop();
                res.push_back(t->val);
                now = t->right;
            }
        }

        return res;
    }
};
```

这里需要注意`now = t->right;`没有加上非空的判断，因为循环条件中右判断。如果 t->right 为空，那么下次循环就会处理栈顶元素，比如动画中的例子：

- 首先处理 1
- 1 的右孩子为空，那么下次循环来处理栈顶元素，栈顶是 4，4 有右孩子 2
- 下次循环 now 非空，2 会被压栈，now 指向 2 的左孩子，是空
- 下次循环会弹出 2，now 指向 2 的右孩子，也是空
- 下次循环就从栈中弹出 5，处理 5
- 5 的右孩子不空，下次处理 6
