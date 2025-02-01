/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack
{
private:
    queue<int> q;
    queue<int> tmp;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
    }

    int pop()
    {
        // 需要弹出队尾元素
        int size = q.size();
        size--; // 需要保留最后一个元素
        while (size--)
        {
            tmp.push(q.front());
            q.pop();
        }
        int res = q.front();
        q.pop();

        // 需要将tmp复制到q，并清除tmp
        q = tmp;
        while (!tmp.empty())
        {
            tmp.pop();
        }
        return res;
    }

    int top()
    {
        // 逻辑同pop，但是不能删除队尾元素
        int size = q.size();
        size--;
        while (size--)
        {
            tmp.push(q.front());
            q.pop();
        }
        int res = q.front();
        tmp.push(res);
        q.pop();

        q = tmp;
        while (!tmp.empty())
        {
            tmp.pop();
        }
        return res;
    }

    bool empty()
    {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
