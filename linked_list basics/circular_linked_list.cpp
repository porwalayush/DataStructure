#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *nxt;
};
void push(Node** headrfr,int val)
{
    Node* newnode= new Node();
    newnode->data= val;
    newnode->nxt= *(headrfr);
    Node* tmp=*(headrfr);

    if(*(headrfr)!=NULL)
    {
        while(tmp->nxt!=*(headrfr))
        tmp=tmp->nxt;
        tmp->nxt=newnode;
    }
    else
    {
        newnode->nxt=newnode;
    }

    *(headrfr)= newnode;
}
void print(Node* n)
{
    Node* tmp =n;
    do
    {
        cout<<tmp->data<<" ";
        tmp=tmp->nxt;
    }
    while(tmp!=n);
}
int main() {
    Node *head=NULL;
    push(&head,4);
    push(&head,9);
    push(&head,5);

    print(head);
    return 0;
}
