/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (69.00%)
 * Likes:    366
 * Dislikes: 0
 * Total Accepted:    45.6K
 * Total Submissions: 66.1K
 * Testcase Example:  '"aab"'
 *
 * 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 * 
 * 返回 s 所有可能的分割方案。
 * 
 * 示例:
 * 
 * 输入: "aab"
 * 输出:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        backtrack(s, path, 0);
        return ans;
    }
private:
    vector<vector<string>> ans;
    void backtrack(string s, vector<string>& path, int pre)
    {
        string temp;
        if(pre == s.size())     //回溯结束
        {
            ans.push_back(path);
            return;
        }
        for(int i = pre; i < s.size(); i++)
        {
            bool flag = true;
            temp = s.substr(pre, i - pre + 1);  //分割字符串
            int wide = temp.size();
            for(int j = 0; j < wide; j++)   //判断回文
            {
                if(temp[j] != temp[wide - j - 1])
                {
                    flag = false;
                    break;
                }
            }
            if(flag == false)
                continue;
            path.push_back(temp);
            backtrack(s, path, i + 1);
            path.pop_back();    //还原
        }
    }
};

// @lc code=end

