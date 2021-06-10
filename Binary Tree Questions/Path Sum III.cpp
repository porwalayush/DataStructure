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
    int sum=0,c=0;
    vector<TreeNode*> s;
    void count(TreeNode* root,int targetsum)
    {
        if(root==NULL)
            return;
        sum+=root->val;
        if(sum==targetsum)
            c++;
        if(!s.empty())
        {
            int pre=0;
            for(int i=0;i<s.size();i++)
            {
                pre+=s[i]->val;
                if(sum-pre==targetsum)
                    c++;
            }
        }
        s.push_back(root);
        count(root->left,targetsum);
        count(root->right,targetsum);
        sum-=root->val;
        s.pop_back();
        return;
    }
    int pathSum(TreeNode* root, int targetSum) {
        count(root,targetSum);
        return c;
    }
};