# 删除链表的倒数第 n 个节点

例题：[leetcode 19 删除链表的倒数第 n 个节点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/)

使用双指针法+虚拟头节点解决。

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *fast = dummy;
        ListNode *slow = dummy;

        // 先操作fast指针
        while (n-- && fast)
        {
            fast = fast->next;
        }
        fast = fast->next; // 走n+1步

        // 然后fast和slow一起移动
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return dummy->next;
    }
};
```

模拟过程：

```
假设链表为：1 -> 2 -> 3 -> 4 -> 5，要删除倒数第 2 个节点

1. 初始状态：
   dummy -> 1 -> 2 -> 3 -> 4 -> 5
   s,f

2. fast 移动 n+1 步（这里 n=2）：
   dummy -> 1 -> 2 -> 3 -> 4 -> 5
   s                  f

3. fast 和 slow 同时移动，直到 fast 到达末尾：
   dummy -> 1 -> 2 -> 3 -> 4 -> 5
                      s         f

4. 删除 slow 的下一个节点：
   dummy -> 1 -> 2 -> 3 ------> 5
                      s

5. 返回 dummy->next，即为新的头节点：
   1 -> 2 -> 3 -> 5

```

假设链表总长度为 L：

1. fast 指针移动情况：

   - 第一阶段：移动 n+1 步
   - 第二阶段：移动到末尾，即还需要 L-(n+1) 步
   - fast 总共移动：(n+1) + [L-(n+1)] = L 步

2. slow 指针移动情况：

   - 第一阶段：不动
   - 第二阶段：和 fast 一起移动 L-(n+1) 步
   - slow 总共移动：0 + [L-(n+1)] = L-(n+1) 步

3. 结论：

   - slow 最终停在倒数第 n 个节点的前一个位置
   - 因为：从 slow 当前位置到末尾还有 n 个节点

4. dummy 节点的作用：
   - 在原链表前加了一个节点，相当于链表长度变成 L+1
   - 统一了处理逻辑，不需要特殊处理删除头节点的情况
