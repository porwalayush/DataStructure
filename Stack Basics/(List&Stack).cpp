#include<iostream>
using namespace std;

class Node
{
public:
  int val;
  Node* next;
};

class List
{
private:
  Node* head;
public:
  List()
  {
    head = NULL;
  }
  bool empty()
  {
    return head == NULL;
  }
  int first_element()
  {
    return head->val;
  }
  void insert_at_beginning(int x)
  {
    if (!head)
    {
      Node* tmp = new Node();
      tmp->val = x;
      tmp->next = NULL;
      head = tmp;
    }
    else
    {
      Node* tmp = new Node();
      tmp->val = x;
      tmp->next = head;
      head = tmp;
    }
  }
  void remove_from_beginning()
  {
    Node* tmp = head;
    head = head->next;
    free(tmp);
  }
};

class stack
{
private:
  List l;
public:
  void push(int x)
  {
    l.insert_at_beginning(x);
  }
  void pop()
  {
    l.remove_from_beginning();
  }
  int top()
  {
    return l.first_element();
  }
  bool empty()
  {
    return l.empty();
  }
};

int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  stack s;
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(2);
  s.push(1);
  s.push(10);
  s.push(10);
  while (!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }
  return 0;
}