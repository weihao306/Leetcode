/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 *
 * https://leetcode-cn.com/problems/number-of-digit-one/description/
 *
 * algorithms
 * Hard (37.80%)
 * Likes:    176
 * Dislikes: 0
 * Total Accepted:    11.3K
 * Total Submissions: 30K
 * Testcase Example:  '13'
 *
 * 给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。
 * 
 * 示例:
 * 
 * 输入: 13
 * 输出: 6 
 * 解释: 数字 1 出现在以下数字中: 1, 10, 11, 12, 13 。
 * 
 */

// @lc code=start
class Solution {
public:
    int countDigitOne(int n) {
        long long digit = 1, res = 0;
        while(n / digit){
            long long high = n / (10 * digit), cur = (n / digit) % 10, low = n - (n / digit) * digit;
            if(cur==0)
                res += high * digit;
            else if(cur==1)
                res += high * digit + low + 1;
            else
                res += (high + 1) * digit;
            digit *= 10;
        }
        return res;
    }
};
// @lc code=end

