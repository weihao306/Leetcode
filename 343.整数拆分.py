#
# @lc app=leetcode.cn id=343 lang=python3
#
# [343] 整数拆分
#
# https://leetcode-cn.com/problems/integer-break/description/
#
# algorithms
# Medium (58.69%)
# Likes:    372
# Dislikes: 0
# Total Accepted:    62.6K
# Total Submissions: 106.6K
# Testcase Example:  '2'
#
# 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
# 
# 示例 1:
# 
# 输入: 2
# 输出: 1
# 解释: 2 = 1 + 1, 1 × 1 = 1。
# 
# 示例 2:
# 
# 输入: 10
# 输出: 36
# 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
# 
# 说明: 你可以假设 n 不小于 2 且不大于 58。
# 
#

# @lc code=start
class Solution:
    def integerBreak(self, n: int) -> int:
        if(n == 1 or n == 2):
            return 1
        if(n == 3):
            return 2
        sum = 1
        while(n > 4):     # 份数越多，3越多 则积越大
            sum *= 3
            n -= 3
        return sum * n

# @lc code=end

