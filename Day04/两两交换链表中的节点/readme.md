# 两两交换链表中的节点

例题：[leetcode 24 两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/description/)

简单模拟即可，注意还是使用了虚拟头节点。

```cpp
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        // 取下标为0的节点，对下标1，2的节点进行互换
        // 0-1-2-3 => 0-2-1-3
        ListNode *now = dummy;
        while (now->next && now->next->next)
        {
            // 开始交换
            ListNode *first = now->next;
            ListNode *third = now->next->next->next;

            // 首先将第二个节点换上来
            now->next = now->next->next;
            // 其次将原先第一个节点放在第二个节点的后面
            now->next->next = first;
            // 最后再连接第三个节点
            now->next->next->next = third;

            // 跳到下个节点
            now = now->next->next;
        }

        return dummy->next;
    }
};
```
