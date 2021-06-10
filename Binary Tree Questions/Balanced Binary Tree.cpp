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
    class Paiir
    {
    public:
        int height;
        bool balanced;
    };
    Paiir check(TreeNode* root)
    {
        Paiir ans;
        if(!root)
        {
            ans.height=0;
            ans.balanced=true;
            return ans;
        }
        Paiir left=check(root->left);
        Paiir right=check(root->right);
        ans.height=max(left.height,right.height)+1;
        if((abs(left.height-right.height))<2 && left.balanced && right.balanced)
            ans.balanced=true;
        else
            ans.balanced=false;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        return check(root).balanced;
    }
};