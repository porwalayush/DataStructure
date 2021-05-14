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
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node* root=build();
    bfs(root);
    return 0;
}