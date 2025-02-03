/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        // 本质和 116 题一样，但是这里我们换成空间复杂度O(1)的方法
        Node *head = root; // 本层头节点，实质上一层就是链表
        while (head)
        {
            Node *dummy = new Node(0); // 下一层的虚拟头节点
            Node *tmp = dummy;

            for (Node *now = head; now != nullptr; now = now->next)
            {
                if (now->left)
                {
                    tmp->next = now->left;
                    tmp = tmp->next;
                }

                if (now->right)
                {
                    tmp->next = now->right;
                    tmp = tmp->next;
                }
            }

            head = dummy->next;
        }
        return root;
    }
};
// @lc code=end

/*
假设我们有这样一棵树:
```
     1
   /  \
  2    3
 / \  / \
4  5  6  7
```

代码的工作原理是这样的:

第一步: 从根节点开始
- head = 1 (根节点)
- 创建一个虚拟节点 dummy (值为0)，用来帮助我们连接下一层
- temp = dummy (用来追踪当前正在处理的位置)

第二步: 处理第一层(节点1)
```
当前状态: 1
处理1的左子节点(2): dummy -> 2
处理1的右子节点(3): dummy -> 2 -> 3
```

第三步: 移动到第二层
- head 更新为 dummy.next (也就是节点2)
- 现在开始处理第二层的节点(2和3)
```
当前状态: 2 -> 3
处理2的左子节点(4): dummy -> 4
处理2的右子节点(5): dummy -> 4 -> 5
处理3的左子节点(6): dummy -> 4 -> 5 -> 6
处理3的右子节点(7): dummy -> 4 -> 5 -> 6 -> 7
```

这个过程的关键点是:
1. 每一层都用一个 dummy 节点作为起点，这样可以统一处理第一个节点和后续节点
2. temp 节点像一个移动的指针，帮助我们把节点连接起来
3. head 节点帮助我们在不同层之间移动
4. 当一层处理完后，我们通过 dummy.next 移动到下一层的第一个实际节点

最终结果会是这样:
```
     1 -> null
   /  \
  2 -> 3 -> null
 / \  / \
4->5->6->7 -> null
```
*/