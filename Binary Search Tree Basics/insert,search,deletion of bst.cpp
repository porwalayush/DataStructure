#include "bits/stdc++.h"
using namespace std;
class Node
{
  public:
  int val;
  Node* left;
  Node* right;

  Node(int d)
  {
    val=d;
    left=NULL;
    right=NULL;
  }
};
void bfs(Node* root)     
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
Node* insert(Node* root,int d)
{
  if(root==NULL)
    return new Node(d);
  if(d<=root->val)
    root->left=insert(root->left,d);
  else
    root->right=insert(root->right,d);
  return root;
}
bool search(Node* root,int d)
{
  if(root==NULL)
    return false;
  if(root->val==d)
    return true;
  if(d<=root->val)
    return search(root->left,d);
  return search(root->right,d);
}
Node* deletion(Node* root,int d)
{
  if(root==NULL)
    return NULL;
  if(root->val>d)
  {
    root->left=deletion(root->left,d);
    return root;
  }
  else if(root->val<d)
  {
    root->right=deletion(root->right,d);
    return root;
  }

    // 0 child
    if(root->left==NULL && root->right==NULL)
      return NULL;


    // 1 child
    if(root->left!=NULL && root->right==NULL)
    {
      Node* tmp=root->left;
      delete(root);
      return tmp;
    }
    if(root->left==NULL && root->right!=NULL)
    {
      Node* tmp=root->right;
      delete(root);
      return tmp;
    }

    // 2 child
    Node* successor=root->right;
    while(successor->left!=NULL)
      successor=successor->left;
    root->val=successor->val;
    root->right=deletion(root->right,successor->val);
    return root;
}
Node* build()
{
  int d;
  cin>>d;
  Node* root=NULL;
  while(d!=-1)
  {
    root=insert(root,d);
    cin>>d;
  }
  return root;
}
int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    Node* root=build();
    bfs(root);
    cout<<((search(root,21))?"YES":"NO");
    cout<<endl;
    bfs(root=deletion(root,10));
    bfs(root=deletion(root,4));
    bfs(root=deletion(root,3));
    return 0;
}

// 10 5 18 3 4 19 11 1 16 6 -1