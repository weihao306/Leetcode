/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 *
 * https://leetcode-cn.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (24.45%)
 * Likes:    496
 * Dislikes: 0
 * Total Accepted:    66.9K
 * Total Submissions: 273.7K
 * Testcase Example:  '"12"'
 *
 * 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 给定一个只包含数字的非空字符串，请计算解码方法的总数。
 * 
 * 示例 1:
 * 
 * 输入: "12"
 * 输出: 2
 * 解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "226"
 * 输出: 3
 * 解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int cur = 1, pre = 1; //dp[-1]=dp[0]=1
        for(int i = 1; i < s.size(); i++)
        {
            int temp = cur;
            if(s[i] == '0')
                if(s[i-1] == '1' || s[i-1] == '2') 
                    cur = pre;
                else
                    return 0;
            else if(s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '1' && s[i] <= '6'))
                cur = cur + pre;
            pre = temp;
        }
        return cur;
    }
};
// @lc code=end

