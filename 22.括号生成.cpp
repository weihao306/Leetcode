/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (76.20%)
 * Likes:    1299
 * Dislikes: 0
 * Total Accepted:    177.2K
 * Total Submissions: 232.6K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：n = 3
 * 输出：[
 * ⁠      "((()))",
 * ⁠      "(()())",
 * ⁠      "(())()",
 * ⁠      "()(())",
 * ⁠      "()()()"
 * ⁠    ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        DFS(ans, "", 0, 0, n);
        return ans;
    }

    void DFS(vector<string> &ans, string str, int l, int r, int n)
    {
        if(l > n || r > n || r > l) return;
        if(l == n && r == n)
        {
            ans.push_back(str);
            return;
        } 
        DFS(ans, str + '(', l+1, r, n);
        DFS(ans, str + ')', l, r+1, n);

        return;
    }
};
// @lc code=end

