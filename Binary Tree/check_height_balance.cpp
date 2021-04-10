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
class paiir
{
public:
    int height;
    bool hbt;
};

// if all the nodes have  abs(left subtree height-right subtree height)<=1
paiir is_HeightBalance(Node* root)
{
    paiir ans;       
    if(root==NULL)                //bottom up implementation
    {
        ans.height=0;
        ans.hbt=true;
        return ans; 
    }
    paiir left=is_HeightBalance(root->left);
    paiir right=is_HeightBalance(root->right);
    ans.height=max(left.height,right.height)+1;
    if(abs(left.height-right.height)<=1 && left.hbt && right.hbt )
        ans.hbt=true;
    else
        ans.hbt=false;
    return ans;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node* root=build();
    if(is_HeightBalance(root).hbt)
        cout<<"HEIGHT BALANCED";
    else
        cout<<"NOT HEIGHT BALANCED";
    return 0;
}