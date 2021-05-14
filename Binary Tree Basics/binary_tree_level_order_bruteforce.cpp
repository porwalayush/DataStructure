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

void print_kth(Node* root,int k)
{
    if(root==NULL)
        return;
    if(k==1)
    {
        cout<<root->val<<" ";
        return;
    }
    print_kth(root->left,k-1);
    print_kth(root->right,k-1);
}

int height_tree(Node* root)
{
    if(root==NULL)
        return 0;
    int l=height_tree(root->left);
    int r=height_tree(root->right);
    return max(l,r)+1;
}

void level_order(Node* root)
{
    int h=height_tree(root); 
    for(int i=1;i<=h;i++)
    {
        print_kth(root,i);     // O(n^2)  for skewed binary tree
        cout<<endl;
    }
    return;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node* root=build();
    level_order(root);
    return 0;
}