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


void rightview(Node* root,int level,int &maxi)
{
    if(root==NULL)
        return;
    if(maxi<level)
    {
        cout<<root->val<<" ";
        maxi=level;
    }
    rightview(root->right,level+1,maxi);
    rightview(root->left,level+1,maxi);
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node* root=NULL;
    cin>>root;
    int maxi=-1;
    rightview(root,0,maxi);
    return 0;
}








/*                using static int                   */
 

// #include<bits/stdc++.h>
// using namespace std;
// class Node
// {
// public:
//     int val;
//     Node*left;
//     Node*right;

//     //constructor
//     Node(int d)
//     {
//         val=d;
//         left=NULL;
//         right=NULL;
//     }
// };

// void levelorderbuild(Node* &root)
// {
//     int d;
//     cin>>d;
//     root= new Node(d);
//     queue<Node*> q;
//     q.push(root);
//     while(!q.empty())
//     {
//         Node* tmp=q.front();
//         q.pop();
//         int ch1,ch2;
//         cin>>ch1>>ch2;
//         if(ch1!=-1)
//         {
//             tmp->left=new Node(ch1);
//             q.push(tmp->left);
//         }
//         if(ch2!=-1)
//         {
//             tmp->right= new Node(ch2);
//             q.push(tmp->right);
//         }
//     }
// } 
// void levelorderprint(Node* root)      
// {
//     queue<Node*> q;
//     q.push(root);
//     q.push(NULL);
//     while(!q.empty())
//     {
//         Node* f=q.front();
//         if(f==NULL)
//         {
//             cout<<endl;
//             q.pop();
//             if(!q.empty())
//                 q.push(NULL);
//         }
//         else
//         {
//         cout<<f->val<<" ";
//         q.pop();
//         if(f->left)      
//         q.push(f->left);
//         if(f->right)
//         q.push(f->right);
//         }
//     }
// }
// istream& operator>>(istream& is , Node* &root)
// {
//     levelorderbuild(root);
//     return is;
// }
// ostream& operator<<(ostream& os, Node* root)
// {
//     levelorderprint(root);
//     return os;
// }


// void rightview(Node* root,int level)
// {
//     static int maxi=-1;
//     // cout<<maxi<<endl;
//     if(root==NULL)
//         return;
//     if(maxi<level)
//     {
//         cout<<root->val<<" ";
//         maxi=level;
//     }
//     rightview(root->right,level+1);
//     rightview(root->left,level+1);
// }
// int main()
// {
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif

//     Node* root=NULL;
//     cin>>root;
    
//     rightview(root,0);
//     return 0;
// }