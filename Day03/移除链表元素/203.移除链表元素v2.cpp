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
// @lc code=end
