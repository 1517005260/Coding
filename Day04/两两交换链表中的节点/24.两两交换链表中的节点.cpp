/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        // 取下标为0的节点，对下标1，2的节点进行互换
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
// @lc code=end
