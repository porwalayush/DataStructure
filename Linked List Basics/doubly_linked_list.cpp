#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* pre;
    Node *nxt;
};
void push(Node** headrfr,int val)
{
    Node* newnode= new Node();
    newnode->data=val;
    newnode->pre=NULL;
    newnode->nxt=*(headrfr);
    if(*(headrfr)!=NULL)
    (*headrfr)->pre=newnode;
    *(headrfr)= newnode;
}
void print(Node* n)
{
    Node* tmp;
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        tmp=n;
        n=n->nxt;
    }
    cout<<endl;
    while(tmp!=NULL)
    {
        cout<<tmp->data<<" ";
        tmp=tmp->pre;
    }
}
int main() {
    Node *head=NULL;
    push(&head,4);
    push(&head,9);
    push(&head,5);
    push(&head,10);

    print(head);
    return 0;
}
