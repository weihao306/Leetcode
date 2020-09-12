/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 *
 * https://leetcode-cn.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (27.43%)
 * Likes:    159
 * Dislikes: 0
 * Total Accepted:    15.4K
 * Total Submissions: 56K
 * Testcase Example:  '1\n2'
 *
 * 给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。
 * 
 * 如果小数部分为循环小数，则将循环的部分括在括号内。
 * 
 * 示例 1:
 * 
 * 输入: numerator = 1, denominator = 2
 * 输出: "0.5"
 * 
 * 
 * 示例 2:
 * 
 * 输入: numerator = 2, denominator = 1
 * 输出: "2"
 * 
 * 示例 3:
 * 
 * 输入: numerator = 2, denominator = 3
 * 输出: "0.(6)"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
    	if(denominator == 0) return "";

    	string result;
		//类型转换，防止溢出
		long long num = static_cast<long long>(numerator);
		long long denom = static_cast<long long>(denominator);

		if((num > 0) ^ (denom > 0))	result.push_back('-');	//处理正负号
		num = llabs(num);
		denom = llabs(denom);	//分子分母都转换为正数

		//整数部分
		result.append(to_string(num / denom));	
		
		//小数部分
		num %= denom;	//获得余数
		if(num == 0)	//余数为0,整除
			return result;	
		result.push_back('.');		//余数不为0,添加小数点
		int index = result.size() - 1;	//获取小数点下标
		unordered_map<int, int> record;	//map用来记录出现重复数的下标，然后将'('插入到重复数的前面
		while(num && record.count(num)==0)	//小数部分：余数不为0且余数还没有出现重复数字
		{   
            record[num]=++index;
            num *= 10;                        //余数扩大10倍，然后求商，和草稿本上运算方法是一样的
            result += to_string(num / denom);
            num %= denom;
        }
        if(record.count(num) == 1)	//出现循环余数，我们直接在重复数字前面添加'(',字符串末尾添加')'
		{           
            result.insert(record[num], "(");
            result.push_back(')');
        }
        return result;
    }
};
// @lc code=end

