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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        int parity=0;
        queue<TreeNode*> d;
        vector<vector<int>> ans;
        d.push(root);
        while(!d.empty())
        {
            vector<int> v;
            int sz=d.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* cur;
                    cur=d.front();
                    v.push_back(cur->val);
                    d.pop();
                    if(cur->left) d.push(cur->left);
                    if(cur->right) d.push(cur->right);
            }
            if(parity)
                reverse(v.begin(),v.end());
            ans.push_back(v);
            parity^=1;
        }
        return ans;
    }
};