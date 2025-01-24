# 移除链表元素

例题：[leetcode 203 移除链表元素](https://leetcode.cn/problems/remove-linked-list-elements/description/)

1. 普通方法，需要对头节点进行特判删除

**特别需要注意删完之后变成空指针的情况**

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
    ListNode *removeElements(ListNode *head, int val)
    {

        if (head == nullptr)
        {
            return nullptr;
        }

        // 特判： 删除头节点
        // 需要使用while，因为可能有多个和头节点相同的值
        while (head != nullptr && head->val == val)
        {
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        }

        // 如果链表是[7,7,7]删完7之后，链表变空了，这里直接返回
        // 并且这种情况，需要向上面的whlie条件添加非空指针判断
        if (head == nullptr)
        {
            return nullptr;
        }

        // 删除普通节点
        ListNode *now = head;
        while (now->next != nullptr)
        {
            if (now->next->val == val)
            {
                // 进行删除操作
                // 删除 now -> next
                ListNode *tmp = now->next;
                now->next = now->next->next;
                delete tmp;
            }
            else
            {
                now = now->next;
            }
        }

        return head;
    }
};
```

时间复杂度 O(n)，空间复杂度 O(1)

2. 增加虚拟头节点（哑节点），使得头节点的删除逻辑可以和普通节点的删除逻辑统一。

```cpp
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // 定义一个虚拟头节点，它的next是head
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        // 接下来的逻辑和删除普通节点一样
        ListNode *now = dummy;
        while (now->next != nullptr)
        {
            if (now->next->val == val)
            {
                ListNode *tmp = now->next;
                now->next = now->next->next;
                delete tmp;
            }
            else
            {
                now = now->next;
            }
        }

        return dummy->next;
    }
};
```

时间复杂度 O(n)，空间复杂度 O(1)
