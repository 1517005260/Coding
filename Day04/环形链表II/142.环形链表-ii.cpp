/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        // fast走两步，slow走一步，判断是否有环
        while (fast && fast->next)
        {
            fast = fast->next->next; // 这里需要访问fast->next，所以while条件需要加上
            slow = slow->next;

            // 判断要写在里面，否则会超时
            if (fast == slow)
            {
                ListNode *index1 = fast;
                ListNode *index2 = head;

                while (index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return nullptr;
    }
};
// @lc code=end
