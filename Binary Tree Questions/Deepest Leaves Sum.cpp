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
    int cur_level=0,ans=0;
    void go(TreeNode* root,int level)
    {
        if(!root) return;
        if(root->left==NULL && root->right==NULL)
        {
            if(cur_level<level)
            {
                cur_level=level;
                ans=root->val;
            }
            else if(cur_level==level)
                ans+=root->val;
        }
        go(root->left,level+1);
        go(root->right,level+1);
        return;
    }
    int deepestLeavesSum(TreeNode* root) {
        go(root,1);
        return ans;
    }
};