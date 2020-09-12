/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (29.41%)
 * Likes:    2571
 * Dislikes: 0
 * Total Accepted:    323.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？请你找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) //不能重复
                continue;
            int k = n - 1;
            int target = -nums[i];
            
            for(int j = i + 1; j < n; j++)
            {
                if(j > i + 1 && nums[j] == nums[j-1])
                    continue;
                while(j < k && nums[j] + nums[k] > target)
                    --k;
                if(j == k)
                    break;
                if(nums[j] + nums[k] == target)
                    ans.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return ans;
    }
};
// @lc code=end

