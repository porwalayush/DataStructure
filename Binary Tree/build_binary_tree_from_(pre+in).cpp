// 8 3 10 -1 -1 6 2 -1 -1 -1 5 4 -1 -1 9 13 -1 -1 -1
//   pre+inorder = 1 unique tree
//   post+inorder = 1 unique tree
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
Node* build(int pre[],int in[],int s,int e)
{
    if(s>e)
        return NULL;
    static int i=0;
    int pos=-1;
    for(int j=s;j<=e;j++)
    {
        if(in[j]==pre[i])
        {
            pos=j;
            break;
        }
    }
    Node* root= new Node(pre[i]);
    i++;
    root->left=build(pre,in,s,pos-1);
    root->right=build(pre,in,pos+1,e);
    return root;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;  // no of nodes
    cin>>n;
    int pre[n],in[n];
    for(int i=0;i<n;i++)
    {
        cin>>pre[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
    }
    bfs(build(pre,in,0,n-1));
    return 0;
}