/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
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
    vector<vector<int>> levelOrder(Node *root)
    {
        // 修改二叉树的加入方式为n叉树即可
        vector<vector<int>> res;
        queue<Node *> q;

        if (root)
        {
            q.push(root);
        }

        while (!q.empty())
        {
            int size = q.size();
            vector<int> vec;

            while (size--)
            {
                Node *t = q.front();
                q.pop();
                vec.push_back(t->val);

                vector<Node *> childs = t->children;
                if (!childs.empty())
                {
                    for (Node *child : childs)
                    {
                        q.push(child);
                    }
                }
            }

            res.push_back(vec);
        }

        return res;
    }
};
// @lc code=end
