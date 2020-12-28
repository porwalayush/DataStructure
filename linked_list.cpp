#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
	int data;
	Node* nxt;
};
void print(Node* n)
{
	if(n==NULL)
	{
		cout<<"Empty List";
		return;
	}
	while(n!=NULL)
	{
		cout<<n->data<<" ";
		n=n->nxt;
	}
	return;
}
int main()
{
	Node* head=NULL;
	Node* second=NULL;
	Node* third=NULL;


	head= new Node();
	second= new Node();
	third = new Node();

	head->data=1;
	head->nxt=second;

	second->data=2;
	second->nxt=third;

	third->data=3;
	third->nxt=NULL;


	print(head);
}