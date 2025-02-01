# 用队列实现栈

例题：[leetcode 225 用队列实现栈](https://leetcode.cn/problems/implement-stack-using-queues/description/)

原理详见下图：

![gif](https://code-thinking.cdn.bcebos.com/gifs/225.%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.gif)

```cpp
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
```

时间复杂度: pop 为 O(n)，top 为 O(n)，其他为 O(1)，空间复杂度: O(n)
