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
void bfs(Node* root)      // O(n)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* f=q.front();
        if(f==NULL)
        {
            cout<<endl;
            q.pop();
            if(!q.empty())
                q.push(NULL);
        }
        else
        {
        cout<<f->val<<" ";
        q.pop();
        if(f->left)      //  can be NULL
        q.push(f->left);
        if(f->right)
        q.push(f->right);
        }
    }
}
Node* buildBalanced(int arr[],int s,int e)
{
    if(s>e)
        return NULL;
    int m=(s+e)/2;
    Node* root= new Node(arr[m]);
    root->left= buildBalanced(arr,s,m-1);
    root->right= buildBalanced(arr,m+1,e);
    return root;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int arr[]={1,2,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(int);
    Node* ans=buildBalanced(arr,0,n-1);
    bfs(ans);
    return 0;
}