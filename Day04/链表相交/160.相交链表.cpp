/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
// @lc code=end
