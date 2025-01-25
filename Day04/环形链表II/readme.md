# 环形链表 II

例题：[leetcode 142 环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/description/)

第一个问题：如何找到环？我们可以使用快慢指针，fast 每次走两步，slow 每次走一步。具体原理如下：

![fast-slow](https://code-thinking.cdn.bcebos.com/gifs/141.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8.gif)

第二个问题：如何返回入环节点？

我们设入环前的长度为`x`，slow 指针在环内走过了`y`，环内剩余长度为`z`，则 fast 指针走的总长度为：`x + y + n(y + z)`。

又有 fast 的速度是 slow 的两倍，所以有：`2(x + y) = x + y + n(y + z)`。解得：`x = n (y + z) - y`。x 的长度就是我们要求解的入口的长度。

`x = n (y + z) - y = (n - 1)(y + z) + z`，由于 fast 指针至少会在环内转一圈（见上 gif），所以 `n ≥ 1`，n=1 时，x=z

**x=z**，这意味着，入口的长度等于环的剩余长度，这时我们可以再用两个指针找到入口位置，如下 gif 所示：

![index1-2](https://code-thinking.cdn.bcebos.com/gifs/142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II%EF%BC%88%E6%B1%82%E5%85%A5%E5%8F%A3%EF%BC%89.gif)

n>1 时，index1 需要多转几圈

```cpp
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
```
