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
    class paiir
    { 
        public:
        int diameter;
        int height;
    };
    paiir diameter(TreeNode* root)
    {
        paiir s;
        if(root==NULL)
        {
            s.diameter=0;
            s.height=0;
            return s;
        }
        paiir left=diameter(root->left);
        paiir right=diameter(root->right);
        s.diameter=max(left.height+right.height,max(left.diameter,right.diameter));
        s.height=max(left.height,right.height)+1;
        return s;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).diameter;
    }
};