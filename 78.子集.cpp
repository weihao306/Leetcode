/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (77.93%)
 * Likes:    748
 * Dislikes: 0
 * Total Accepted:    131.4K
 * Total Submissions: 168.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.emplace_back(vector<int>{});    //空集

        vector<int> temp;   //临时变量
        for(int i = 0; i < nums.size(); i++)
        {
            int size = ans.size();
            for(int j = 0; j < size; j++)
            {
                temp = ans[j];  
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
// @lc code=end

