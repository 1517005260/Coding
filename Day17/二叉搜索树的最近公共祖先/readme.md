# 二叉搜索树的最近公共祖先

例题：[leetcode 235 二叉搜索树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/description/)

相对于昨天的[二叉树的最近公共祖先](../../Day16/二叉树的最近公共祖先/)，二叉搜索树最大的特点就是有序，我们需要在遍历时用上这个性质：

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *ancestor = root;

        // 由于本树是有序的
        // 所以，我们只需要找到分叉点即可
        while (true)
        {
            if (ancestor->val > p->val && ancestor->val > q->val)
            {
                ancestor = ancestor->left;
            }
            else if (ancestor->val < p->val && ancestor->val < q->val)
            {
                ancestor = ancestor->right;
            }
            else
            {
                // 分叉点，例如 p < ancestor < q
                break;
            }
        }

        return ancestor;
    }
};
```
