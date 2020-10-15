/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 *
 * https://leetcode-cn.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (42.06%)
 * Likes:    428
 * Dislikes: 0
 * Total Accepted:    78.5K
 * Total Submissions: 186.7K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n5'
 *
 * 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：
 * 
 * 
 * 每行的元素从左到右升序排列。
 * 每列的元素从上到下升序排列。
 * 
 * 
 * 示例:
 * 
 * 现有矩阵 matrix 如下：
 * 
 * [
 * ⁠ [1,   4,  7, 11, 15],
 * ⁠ [2,   5,  8, 12, 19],
 * ⁠ [3,   6,  9, 16, 22],
 * ⁠ [10, 13, 14, 17, 24],
 * ⁠ [18, 21, 23, 26, 30]
 * ]
 * 
 * 
 * 给定 target = 5，返回 true。
 * 
 * 给定 target = 20，返回 false。
 * 
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int rowSize = matrix.size(), columnSize = matrix[0].size();
        int row = 0, column = columnSize - 1;
        while(row < rowSize && column >= 0 && !matrix.empty())
        {
            // 从矩阵的右上角开始匹配，如果匹配到了，返回true
            if(matrix[row][column] == target) return true;
            // 如果值比target小，则说明这一行都比target小，row往下移一行
            else if(matrix[row][column] < target) row ++;
            // 如果值比target大，说明这一列都比target大，column往左移一行
            else column --;
        }
        return false;
    }
};
// @lc code=end

