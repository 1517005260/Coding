/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> map;
        int cnt = 0;
        for (int a : nums1)
        {
            for (int b : nums2)
            {
                // 遍历这组数组的所有元素，存放至map<数组和，该和出现次数>
                map[a + b]++;
            }
        }

        for (int c : nums3)
        {
            for (int d : nums4)
            {
                int index = 0 - (c + d); // a + b的和
                if (map.find(index) != map.end())
                {
                    cnt += map[index];
                }
            }
        }

        return cnt;
    }
};
// @lc code=end
