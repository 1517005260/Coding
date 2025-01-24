/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
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
// @lc code=end
