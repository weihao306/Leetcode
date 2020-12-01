/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 *
 * https://leetcode-cn.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (54.32%)
 * Likes:    407
 * Dislikes: 0
 * Total Accepted:    37K
 * Total Submissions: 68.1K
 * Testcase Example:  '10'
 *
 * 编写一个程序，找出第 n 个丑数。
 * 
 * 丑数就是质因数只包含 2, 3, 5 的正整数。
 * 
 * 示例:
 * 
 * 输入: n = 10
 * 输出: 12
 * 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
 * 
 * 说明:  
 * 
 * 
 * 1 是丑数。
 * n 不超过1690。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 0) 
            return 0;
        vector<int> ugly(n, 0);
        ugly[0] = 1;    //第一个丑数是1
        //初始分别指向三个有序链表第一个元素,这三个有序链表是想象出来的，分别就是ugly数组元素分别乘以2,3,5得到的
        int i = 0, j = 0, k = 0;    
        for(int index = 1; index < n; index++)
        {
            int temp = min(ugly[i]*2, min(ugly[j]*3, ugly[k]*5));
            if(temp == ugly[i]*2)
                ++i;
            if(temp == ugly[j]*3)
                ++j;
            if(temp == ugly[k]*5)
                ++k;
            ugly[index] = temp;
        }
        return ugly[n-1];
    }
};
// @lc code=end

