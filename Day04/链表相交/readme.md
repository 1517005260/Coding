# 链表相交

例题：[leetcode 160 链表相交](https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/description/)

简单模拟即可。由于一定是在链表末尾出现交点，所以我们让两个链表从尾部对齐。接着，可以让 head 指针指向短链表头，以及长链表对齐后的对应位置，开始遍历寻找相交节点。

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *nowA = headA;
        ListNode *nowB = headB;
        int lenA = 0, lenB = 0;

        // 找出链表长度
        while (nowA)
        {
            lenA++;
            nowA = nowA->next;
        }
        while (nowB)
        {
            lenB++;
            nowB = nowB->next;
        }

        nowA = headA;
        nowB = headB;

        // 这里为了方便，我们令lenA是更长的一方
        if (lenA < lenB)
        {
            swap(lenA, lenB);
            swap(nowA, nowB);
        }

        // 现在我们有长链表A和短链表B
        int delta = lenA - lenB; // 长度差
        while (delta--)
        {
            nowA = nowA->next;
        }

        // 现在A，B应该是尾对齐的，并且nowA和nowB是平行的
        while (nowA)
        {
            if (nowA == nowB)
            {
                return nowA;
            }
            nowA = nowA->next;
            nowB = nowB->next;
        }

        // 没有相交
        return nullptr;
    }
};
```
