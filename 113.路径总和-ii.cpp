/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (60.98%)
 * Likes:    354
 * Dislikes: 0
 * Total Accepted:    95K
 * Total Submissions: 155.8K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<int> pass;
        backtrack(root, sum, pass);
        return ans;
    }
private:
    vector<vector<int>> ans;
    void backtrack(TreeNode* root, int sum, vector<int>& pass)
    {
        if(root == nullptr)
            return;
        //到达叶子结点，且路径和为目标值
        else if(root->left == nullptr && root->right == nullptr && sum - root->val == 0)
        {
            pass.push_back(root->val);
            ans.push_back(pass);
            pass.pop_back();
            return;
        }
        pass.push_back(root->val);  //加入可能解
        backtrack(root->left, sum - root->val, pass);
        backtrack(root->right, sum - root->val, pass);
        pass.pop_back();    //回溯
    }
};
// @lc code=end

