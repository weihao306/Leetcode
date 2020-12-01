/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (68.30%)
 * Likes:    718
 * Dislikes: 0
 * Total Accepted:    122K
 * Total Submissions: 178.7K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, 0, inorder.size()-1);
    }
    TreeNode *build(vector<int>& preorder, vector<int>& inorder, int root, int start, int end)
    {
        if(start > end) 
            return nullptr;
        TreeNode *tree = new TreeNode(preorder[root]);
        int index = start;
        while(index < end && preorder[root] != inorder[index]) index++;
        tree->left = build(preorder, inorder, root + 1, start, index - 1);
        tree->right = build(preorder, inorder, root + 1 + index - start, index + 1, end);
        return tree;
    }
};
// @lc code=end

