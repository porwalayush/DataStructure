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
class paiir
{
public:
    int height;
    int diameter;
};

paiir h_dimeter(Node* root)
{
    paiir s;
    if(root==NULL)                        // bottom up
    {
        s.height=0;
        s.diameter=0;
        return s;
    }
    paiir left=h_dimeter(root->left);
    paiir right=h_dimeter(root->right);
    s.height=max(left.height,right.height)+1;
    s.diameter=max(left.height+right.height,max(left.diameter,right.diameter));
    return s;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node* root=build();
    paiir ans= h_dimeter(root);
    cout<<ans.height<<" "<<ans.diameter;
    return 0;
}