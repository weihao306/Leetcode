/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (43.26%)
 * Likes:    624
 * Dislikes: 0
 * Total Accepted:    124.7K
 * Total Submissions: 288.2K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* current = head;
        vector<int> v;
        while(current != nullptr)
        {
            v.push_back(current->val);
            current = current -> next;
        }
        vector<int> newv = reverseArray(v);
        return newv == v;
    }
    vector<int> reverseArray(vector<int> v)  //反转数组
    {
        int n = v.size();
        for(int i = 0; i < n / 2; i++)
            swap(v[n-i-1], v[i]);
        return v;
    }
};
// @lc code=end

