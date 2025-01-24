/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
// @lc code=end
