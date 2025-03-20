/*
 * @lc app=leetcode.cn id=496 lang=cpp
 * @lcpr version=30104
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res(nums1.size(), -1); // 依题意不满足是-1，所以初始化为-1

        stack<int> s; // 存放nums2的下标

        unordered_map<int, int> map; // 用于快速找到num1[i] == nums2[j]

        for (int i = 0; i < nums1.size(); i++)
        {
            map[nums1[i]] = i;
        }

        for (int j = 0; j < nums2.size(); j++)
        {
            while (!s.empty() && nums2[j] > nums2[s.top()])
            {
                // 这里还需要判断nums1里是否有这个元素
                int idx2 = s.top();
                s.pop();
                if (map.count(nums2[idx2]) > 0)
                {
                    int idx1 = map[nums2[idx2]];
                    res[idx1] = nums2[j];
                }
            }

            s.push(j);
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,1,2]\n[1,3,4,2].\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n[1,2,3,4].\n
// @lcpr case=end

 */
