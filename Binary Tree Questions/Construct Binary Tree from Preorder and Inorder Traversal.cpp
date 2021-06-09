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
    int idx=0;
    map<int,int>m;
    TreeNode* build(vector<int>& preorder,int s,int e)
    {
        if(s>e) return NULL;
        int i=m[preorder[idx]];
        return new TreeNode(preorder[idx++],build(preorder,s,i-1),build(preorder,i+1,e));
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        return build(preorder,0,preorder.size()-1);
    }
};