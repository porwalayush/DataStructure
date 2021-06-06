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
    void build(TreeNode* root, string &s)
    {
        if(!root) return;
        s+=(to_string(root->val));
        if(!root->left && !root->right) return; // we can omit both brackets
        s+="(";
        if(root->left)
        {
            build(root->left,s);
        }
        s+=")";
        if(root->right)
        {
            s+="("; // not requires when right is null we can omit
            build(root->right,s);
            s+=")";
        }
    }
    string tree2str(TreeNode* root) {
        string s="";
        build(root,s);
        return s;
    }
};