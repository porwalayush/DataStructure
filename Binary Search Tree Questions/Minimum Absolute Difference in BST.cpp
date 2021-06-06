/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int mn=INT_MAX,pre=-1e6;
    // because inorder of bst is sorted
    void helper(TreeNode* root)
    {
        if(!root) return;
        helper(root->left);
        mn=min(mn,root->val-pre);
        pre=root->val;
        helper(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        helper(root);
        return mn;
    }
};