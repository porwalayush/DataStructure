#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node*left;
    Node*right;

    //constructor
    Node(int d)
    {
        val=d;
        left=NULL;
        right=NULL;
    }
};

Node* build()
{
    int n;
    cin>>n;
    // cout<<n<<" ";
    if(n==-1)
        return NULL;
    Node* root= new Node(n);
    root->left=build();
    root->right=build();
    return root;
}

int height_tree(Node* root)
{
    if(root==NULL)
        return 0;
    int l=height_tree(root->left);
    int r=height_tree(root->right);
    return max(l,r)+1;
}

int diameter(Node* root)
{
    if(root==NULL)                         //top down
        return 0;
    int op1=height_tree(root->left)+height_tree(root->right);    //O(n) for all n in worst
    int op2=diameter(root->left);                                // O(n^2)
    int op3=diameter(root->right);
    return max(op1,max(op2,op3));
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node* root=build();
    cout<<diameter(root);
    return 0;
}