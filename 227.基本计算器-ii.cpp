// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 *
 * https://leetcode-cn.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (37.27%)
 * Likes:    177
 * Dislikes: 0
 * Total Accepted:    23.5K
 * Total Submissions: 63.1K
 * Testcase Example:  '"3+2*2"'
 *
 * 实现一个基本的计算器来计算一个简单的字符串表达式的值。
 * 
 * 字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。
 * 
 * 示例 1:
 * 
 * 输入: "3+2*2"
 * 输出: 7
 * 
 * 
 * 示例 2:
 * 
 * 输入: " 3/2 "
 * 输出: 1
 * 
 * 示例 3:
 * 
 * 输入: " 3+5 / 2 "
 * 输出: 5
 * 
 * 
 * 说明：
 * 
 * 
 * 你可以假设所给定的表达式都是有效的。
 * 请不要使用内置的库函数 eval。
 * 
 * 
 */
// @lc code=start
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int ans = 0, num = 0;
        char sign = '+';
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= '0')    //string -> int
                num = num * 10 + (s[i] - '0');
            //运算符或最后一个数字，计算上一个符号的结果并入栈
            if(s[i] < '0' && s[i] != ' ' || i == s.size() - 1)
            {
                int pre;
                switch (sign)
                {
                case '+':
                    st.push(num);
                    break;
                case '-':
                    st.push(-num);
                    break;
                case '*':
                    pre = st.top();
                    st.pop();
                    st.push(pre * num);
                    break;
                case '/':
                    pre = st.top();
                    st.pop();
                    st.push(pre / num);
                    break;
                default:
                    break;
                }
                sign = s[i];
                num = 0;    //上一个符号计算完成，更新符号，数字清零
            }
        }
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
// @lc code=end

