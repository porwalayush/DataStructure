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
    void sol1(TreeNode* root1, vector<int>& leaffirst)
    {
        if(root1==NULL) return;
        if(root1->left== NULL && root1->right==NULL) 
        {
            leaffirst.push_back(root1->val);
            return;
        }
        sol1(root1->left,leaffirst);
        sol1(root1->right,leaffirst);
        return;
    }
    void sol2(TreeNode* root2, vector<int>& leafsecond)
    {
        if(root2==NULL) return;
        if(root2->left== NULL && root2->right==NULL) 
        {
            leafsecond.push_back(root2->val);
            return;
        }
        sol2(root2->left,leafsecond);
        sol2(root2->right,leafsecond);
        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaffirst,leafsecond;
        sol1(root1,leaffirst);
        sol2(root2,leafsecond);
        return leaffirst==leafsecond;
    }
};