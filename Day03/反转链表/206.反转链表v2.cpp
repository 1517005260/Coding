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
// @lc code=end
