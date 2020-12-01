/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (41.35%)
 * Likes:    521
 * Dislikes: 0
 * Total Accepted:    86.4K
 * Total Submissions: 208.8K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 输出: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return {};
        int row = matrix.size(), col = matrix[0].size();
        vector<int> ans;
        int up = 0, down = row - 1, left = 0, right = col - 1;
        while(true)
        {
            for(int i = left; i <= right; i++)
                ans.push_back(matrix[up][i]);
            if(++up > down)
                break;
            for(int i = up; i <= down; i++)
                ans.push_back(matrix[i][right]);
            if(--right < left)
                break;
            for(int i = right; i >= left; i--)
                ans.push_back(matrix[down][i]);
            if(--down < up)
                break;
            for(int i = down; i >= up; i--)
                ans.push_back(matrix[i][left]);
            if(++left > right)
                break;
        }
        return ans;
    }
};
// @lc code=end

