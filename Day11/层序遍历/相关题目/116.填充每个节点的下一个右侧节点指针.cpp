/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        queue<Node *> q;
        if (root)
        {
            q.push(root);
        }

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Node *t = q.front();
                q.pop();

                if (i < size - 1) // 如果不是最后一个节点
                {
                    t->next = q.front(); // 那么需要和右边节点连接，而右边的节点由层序遍历，应该在队列的下一位
                }

                if (t->left)
                {
                    q.push(t->left);
                }

                if (t->right)
                {
                    q.push(t->right);
                }
            }
        }

        return root;
    }
};
// @lc code=end
