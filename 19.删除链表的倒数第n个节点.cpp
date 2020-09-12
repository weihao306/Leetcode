/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (39.41%)
 * Likes:    984
 * Dislikes: 0
 * Total Accepted:    231.4K
 * Total Submissions: 587K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 
 * 示例：
 * 
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 
 * 
 * 说明：
 * 
 * 给定的 n 保证是有效的。
 * 
 * 进阶：
 * 
 * 你能尝试使用一趟扫描实现吗？
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next)    //空链表
            return NULL;
        ListNode *fast = head, *slow =head;  //双指针
        for(int i = 0; i < n; i++)  //快指针比慢指针多走n步
            fast = fast->next;
        if(!fast)   //若删除第一个节点，直接返回head->next
            return head->next;
        //双指针同时遍历链表
        while(fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        } 
        slow->next = slow->next->next;  //删除慢指针指向的节点（即倒数第n个节点）
        return head;
    }
};
// @lc code=end

