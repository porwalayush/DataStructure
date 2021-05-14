#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* nxt;
};
void push(Node** headrfc,int data)
{
    Node* newnode = new Node();
    newnode->data=data;
    newnode->nxt = *(headrfc);
    *(headrfc) =newnode;
}
void push_after(Node** headrfc,int val)
{
    Node* newnode= new Node();
    newnode->data=val;
    newnode->nxt=NULL;
    Node* n = *(headrfc);
    if(n==NULL)
    {
        *(headrfc)=newnode;
        return;
    }
    while(n->nxt!=NULL)
    {
        n=n->nxt;
    }
    n->nxt=newnode;
}
void print(Node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->nxt;
    }
    cout<<endl;
}
void deleete(Node* n,int val)
{
    Node* pre= new Node();
    while(n!=NULL && n->data!=val)
    {
        pre=n;
        n=n->nxt;
    }
    if(n==NULL)
    return;
    pre->nxt=n->nxt;
    delete(n);
    return;
}
int no_of_elements(Node* n)
{
    int c=0;
    while(n!=NULL)
    {
        c++;
        n=n->nxt;
    }
    return c;
}
void search(Node* n,int val)
{
    int pos=1;
    while(n!=NULL && n->data!=val)
    {
        n=n->nxt;
        pos++;
    }
    if(n==NULL)
    cout<<"Element not present"<<endl;
    else
    cout<<pos<<endl;
}
void swap(Node** n,int x,int y)
{
    if(x==y) return;
    Node* curx=*n,*prex=NULL;
    while(curx!=NULL && curx->data!=x)
    {
        prex=curx;
        curx=curx->nxt;
    }
    Node* cury=*n,*prey=NULL;
    while(cury!=NULL && cury->data!=y)
    {
        prey=cury;
        cury=cury->nxt;
    }
    if(curx==NULL || cury==NULL)
    return;

    if(prex!=NULL)
    {
        prex->nxt=cury;
    }
    else
    {
        *n=cury;
    }
    if(prey!=NULL)
    {
        prey->nxt=curx;
    }
    else
    {
        *n=curx;
    }
    Node* tmp= curx->nxt;
    curx->nxt=cury->nxt;
    cury->nxt=tmp;
}
int main() {
    Node* head=NULL;

    push_after(&head,18);
    push(&head,4);
    push(&head,1);
    push(&head,8);
    push(&head,5);
    push(&head,3);
    push_after(&head,10);

    print(head);
    deleete(head,5);
    print(head);

    cout<<no_of_elements(head)<<endl;

    search(head,19);
    swap(&head,1,10);
    print(head);
    return 0;
}
