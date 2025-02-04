/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    int maxDepth(Node *root)
    {
        // 层序遍历法
        queue<Node *> q;
        if (root)
        {
            q.push(root);
        }

        int depth = 0;
        while (!q.empty())
        {
            int size = q.size();
            depth++;

            while (size--)
            {
                Node *t = q.front();
                q.pop();

                vector<Node *> childs = t->children;
                for (Node *child : childs)
                {
                    q.push(child);
                }
            }
        }
        return depth;
    }
};
// @lc code=end
