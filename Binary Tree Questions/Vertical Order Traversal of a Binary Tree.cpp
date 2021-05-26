The vertical order traversal of a binary tree is a list of top-to-bottom orderings
for each column index starting from the leftmost column and ending on the rightmost column.
There may be multiple nodes in the same row and same column. 
In such a case, sort these nodes by their values.




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
    map<int,vector<pair<int,int>>> m;
    static bool cmp(pair<int,int>& a,pair<int,int>& b)
    {
        if(a.second!=b.second)
            return a.second<b.second;
        else
            return a.first<b.first;
    }
    void traverse(TreeNode* root,int level,int row)
    {
        if(root==NULL)
            return;
        m[level].push_back({root->val,row});
        traverse(root->left,level-1,row+1);
        traverse(root->right,level+1,row+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        traverse(root,0,0);
        for(auto it:m)
        {
            vector<int> tmp;
            sort(it.second.begin(),it.second.end(),cmp);
            for(auto it1:it.second)
            tmp.push_back(it1.first);
            ans.push_back(tmp);
        }
        return ans;
    }
};