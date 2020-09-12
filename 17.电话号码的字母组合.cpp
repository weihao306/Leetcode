/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (55.47%)
 * Likes:    911
 * Dislikes: 0
 * Total Accepted:    175.4K
 * Total Submissions: 316.2K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> ans;
    string cur;
    map<char, string> mp = {{'2', "abc"}, 
                            {'3', "def"},
                            {'4', "ghi"},
                            {'5', "jkl"},
                            {'6', "mon"},
                            {'7', "pqrs"},
                            {'8', "tuv"},
                            {'9', "wxyz"}};

    vector<string> letterCombinations(string digits) {
        if(!digits.size())
            return ans;
        DFS(digits);
        return ans;
    }

    void DFS(string digits)
    {
        if(!digits.size())
            ans.push_back(cur);
        else
        {
            char num = digits[0];
            string letter = mp[num];
            for(int i = 0; i < letter.size(); i++)
            {
                cur.push_back(letter[i]);
                DFS(digits.substr(1));
                cur.pop_back();
            }
        } 
    }
};
// @lc code=end

