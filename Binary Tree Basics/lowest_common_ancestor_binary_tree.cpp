//1 2 3 4 5 -1 -1 6 7 8 9 -1 -1 10 11 -1 -1 -1 -1 -1 -1 -1 -1
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

void levelorderbuild(Node* &root)
{
    int d;
    cin>>d;
    root= new Node(d);
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* tmp=q.front();
        q.pop();
        int ch1,ch2;
        cin>>ch1>>ch2;
        if(ch1!=-1)
        {
            tmp->left=new Node(ch1);
            q.push(tmp->left);
        }
        if(ch2!=-1)
        {
            tmp->right= new Node(ch2);
            q.push(tmp->right);
        }
    }
} 
void levelorderprint(Node* root)      
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
        if(f->left)      
        q.push(f->left);
        if(f->right)
        q.push(f->right);
        }
    }
}
istream& operator>>(istream& is , Node* &root)
{
    levelorderbuild(root);
    return is;
}
ostream& operator<<(ostream& os, Node* root)
{
    levelorderprint(root);
    return os;
}

void atlevelk(Node* root,int k)
{
    if(root==NULL)
        return;
    if(k==0)
    {
        cout<<root->val<<" ";
        return;
    }
    atlevelk(root->left,k-1);
    atlevelk(root->right,k-1);
}
// assumption is all elements are unique and present
Node* lca(Node* root,int a,int b)
{
    if(root==NULL)
        return NULL;
    if(root->val==a || root->val==b)
        return root;
    Node* leftans= lca(root->left,a,b);
    Node* rightans= lca(root->right,a,b);
    if(leftans!=NULL && rightans!=NULL)    // first node which contains a in left and b in right or vice versa
        return root;
    if(leftans!=NULL)
        return leftans;
    return rightans;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node* root=NULL;
    cin>>root;
    cout<<lca(root,6,8)->val<<endl;
    cout<<lca(root,6,11)->val<<endl;
    cout<<lca(root,10,3)->val<<endl;
    return 0;
}