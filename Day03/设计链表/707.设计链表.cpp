/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList
{
private:
    // 自定义链表结构体
    struct ListNode
    {
        int val;
        ListNode *next;

        // 初始化方法：
        ListNode(int v) : val(v), next(nullptr) {}
    };

    // 自定义成员变量，这里_代表是私有
    ListNode *_dummy; // 虚拟头节点
    int _size;        // 链表大小

public:
    // 初始化方法
    MyLinkedList()
    {
        _dummy = new ListNode(0);
        _size = 0;
    }

    int get(int index)
    {
        if (index >= _size || index < 0) // 最大下标 _size -1
        {
            return -1;
        }

        // 返回第index个节点的值
        ListNode *now = _dummy->next; // 从真实头节点开始找
        while (index--)
        {
            now = now->next;
        }

        return now->val;
    }

    void addAtHead(int val)
    {
        // val 是新的头节点
        ListNode *new_head = new ListNode(val);
        new_head->next = _dummy->next;
        _dummy->next = new_head;
        _size++;
    }

    void addAtTail(int val)
    {
        // val 是新的尾节点
        ListNode *new_tail = new ListNode(val);

        ListNode *now = _dummy;
        while (now->next != nullptr)
        {
            now = now->next;
        }
        now->next = new_tail;
        _size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > _size)
        {
            return;
        }

        if (index <= 0)
        {
            return addAtHead(val);
        }

        if (index == _size)
        {
            return addAtTail(val);
        }

        // 插入到 index - 1 的位置
        ListNode *node = new ListNode(val);
        ListNode *now = _dummy; // 这里需要注意下标位置，是插入到index之前
        while (index--)
        {
            now = now->next;
        }
        node->next = now->next;
        now->next = node;
        _size++;
    }

    void deleteAtIndex(int index)
    {
        if (index >= _size || index < 0)
        {
            return;
        }

        ListNode *now = _dummy;
        while (index--)
        {
            now = now->next;
        }
        now->next = now->next->next;
        _size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
