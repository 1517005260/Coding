/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue
{
private:
    stack<int> _In;
    stack<int> _Out;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        _In.push(x);
    }

    int pop()
    {
        // 出队列，需要先把_In的所有元素放入_Out中，再出栈
        // 如果_Out中有元素，那先弹出
        if (_Out.empty())
        {
            while (!_In.empty())
            {
                _Out.push(_In.top());
                _In.pop();
            }
        }
        int front = _Out.top();
        _Out.pop();
        return front;
    }

    int peek()
    {
        // 复用pop
        int front = this->pop();
        // 将pop的元素塞回去
        _Out.push(front);
        return front;
    }

    bool empty()
    {
        // 两个栈全空即队列空
        return _In.empty() && _Out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
