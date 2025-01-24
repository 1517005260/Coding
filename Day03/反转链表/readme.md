# 反转链表

例题：[leetcode 206 反转链表](https://leetcode.cn/problems/reverse-linked-list/description/)

两种写法本质上是一样的，都是用两个指针，now 和 previous，不断地让 now 指向 previous

1. 双指针法：

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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *previous = nullptr;
        ListNode *now = head;
        ListNode *next_node; // now -> next

        // 不断地让 now -> previous
        while (now)
        {
            next_node = now->next;
            now->next = previous;
            previous = now;
            now = next_node;
        }
        // 最后循环结束时，now == nullptr，previous == 原尾节点
        return previous;
    }
};
```

2. 递归写法

```cpp
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        return reverse(head, nullptr);
    }

    ListNode *reverse(ListNode *now, ListNode *previous)
    {
        if (now == nullptr)
        {
            return previous; // 对应双指针写法的循环结束条件
        }

        ListNode *next_node = now->next;
        now->next = previous; // 进行反转
        return reverse(next_node, now);
    }
};
```

递归的时间和空间复杂度都是 O(n)，因为递归会调用 n 层栈空间（递归深度等于链表长度 n）
