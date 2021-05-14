// 8 3 10 -1 -1 6 2 -1 -1 -1 5 4 -1 -1 9 13 -1 -1 -1
// except of leaf node, we need to replace the node with its childrens value sum;
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
int sum_replacement(Node* root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return root->val;
    int left=sum_replacement(root->left);
    int right=sum_replacement(root->right);
    int tmp=root->val;
    root->val=left+right;
    return root->val+tmp;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node* root=build();
    bfs(root);
    cout<<endl;
    sum_replacement(root);
    bfs(root);
    return 0;
}