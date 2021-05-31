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
    class LinkedList
    {
        public:
        TreeNode* head;
        TreeNode* tail;
    };
    LinkedList flatten_helper(TreeNode* root)
    {
        LinkedList p;
        if(root==NULL)
        {
            p.head=p.tail=NULL;
            return p;
        }
        if(root->left==NULL && root->right==NULL)
        {
            p.head=p.tail=root;
            return p;
        }
        if(root->left!=NULL && root->right==NULL)
        {
            LinkedList leftll=flatten_helper(root->left);
            root->left=NULL;
            TreeNode* tmp=root->right;
            root->right=leftll.head;
            p.head=root;
            p.tail=leftll.tail;
            return p;
        }
        if(root->left==NULL && root->right!=NULL)
        {
            LinkedList rightll=flatten_helper(root->right);
            p.head=root;
            p.tail=rightll.tail;
            return p;
        }
            LinkedList leftll=flatten_helper(root->left);
            LinkedList rightll=flatten_helper(root->right);
            root->left=NULL;
            TreeNode* tmp=root->right;
            root->right=leftll.head;
            leftll.tail->right=tmp;
            p.head=root;
            p.tail=rightll.tail;
            return p;
        
    }
    void flatten(TreeNode* root) {
        root=(flatten_helper(root)).head;
    }
};