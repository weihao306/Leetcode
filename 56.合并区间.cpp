/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (43.02%)
 * Likes:    601
 * Dislikes: 0
 * Total Accepted:    142.5K
 * Total Submissions: 331.3K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: intervals = [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 * 注意：输入类型已于2019年4月15日更改。 请重置默认代码定义以获取新方法签名。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * intervals[i][0] <= intervals[i][1]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size();)
        {
            int t = intervals[i][1];
            int j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= t) 
            {
                t = max(t, intervals[j][1]);
                j++;
            }
            ans.push_back({ intervals[i][0], t });
            i = j;
        }
        return ans;
    }
};
// @lc code=end

