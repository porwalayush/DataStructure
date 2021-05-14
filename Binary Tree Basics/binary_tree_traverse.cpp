// 8 3 10 -1 -1 6 2 -1 -1 -1 5 4 -1 -1 9 13 -1 -1 -1
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

void print_preorder(Node* root)
{
    if(root==NULL)
        return;
    cout<<root->val<<" ";
    print_preorder(root->left);
    print_preorder(root->right);
}

void print_inorder(Node* root)
{
    if(root==NULL)
        return;
    print_inorder(root->left);
    cout<<root->val<<" ";
    print_inorder(root->right);
}

void print_postorder(Node* root)
{
    if(root==NULL)
        return;
    print_postorder(root->left);
    print_postorder(root->right);
    cout<<root->val<<" ";
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node* root=build();
    print_preorder(root); cout<<endl;
    print_inorder(root);  cout<<endl;
    print_postorder(root);  cout<<endl;
    return 0;
}