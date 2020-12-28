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
void print(Node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->nxt;
    }
}
int main() {
    Node* head=NULL;

    push(&head,4);
    push(&head,1);
    push(&head,8);
    push(&head,5);
    push(&head,3);

    print(head);
    return 0;
}
