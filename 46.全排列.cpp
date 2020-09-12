/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (76.81%)
 * Likes:    882
 * Dislikes: 0
 * Total Accepted:    189.7K
 * Total Submissions: 247K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(ans, nums, 0, int(nums.size()));
        return ans;
    }
private:
    void backtrack(vector<vector<int>>& ans, vector<int>& output, int first, int len)
    {
        //所有数都遍历完成
        if(first == len)
        {
            ans.emplace_back(output);
            return;
        }
        for(int i = first; i < len; i++)
        {
            swap(output[i], output[first]);
            backtrack(ans, output, first + 1, len);
            swap(output[i], output[first]);
        }
    }
};
// @lc code=end

