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
class LinkedList
{
public:
  Node* head;
  Node* tail;
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
LinkedList flatten(Node* root)
{
  LinkedList l;
  if(root==NULL)
  {
    l.head=l.tail=NULL;
    return l;
  }

  // for leaf node
  if(root->left==NULL && root->right==NULL)
  {
    l.head=l.tail=root;
    return l;
  }

  // if right is null
  if(root->left!=NULL && root->right==NULL)
  {
    LinkedList leftll=flatten(root->left);
    leftll.tail->right=root;
    l.head=leftll.head;
    l.tail=root;
    return l;
  }

  // if left is null
  if(root->left==NULL && root->right!=NULL)
  {
    LinkedList rightll=flatten(root->right);
    root->right=rightll.head;
    l.head=root;
    l.tail=rightll.tail;
    return l;
  }

  // both not null
  LinkedList leftll=flatten(root->left);
  LinkedList rightll=flatten(root->right);
  leftll.tail->right=root;
  root->right=rightll.head;
  l.head=leftll.head;
  l.tail=rightll.tail;
  return l;
}
int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    Node* root=build();
    bfs(root);
    cout<<endl;
    LinkedList l=flatten(root);
    Node* ptr=l.head;
    while(ptr!=NULL)
    {
      cout<<ptr->val<<"-->";
      ptr=ptr->right;
    }
    return 0;
}

// 10 5 18 3 4 19 11 1 16 6 -1