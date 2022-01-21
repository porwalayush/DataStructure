// using another stack
#include<bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  stack<int> s;
  s.push(3);
  s.push(4);
  s.push(1);
  s.push(2);
  int sz=s.size();
  stack<int> tmp;
  while(!s.empty())
  {
    int tp=s.top();
    s.pop();
    while(!tmp.empty() && tmp.top()>tp)
    {
      s.push(tmp.top());
      tmp.pop();
    }
    tmp.push(tp);
  }
  while(!tmp.empty())
  {
    cout<<tmp.top();
    tmp.pop();
  }
  return 0;
}


// using recursion
#include "bits/stdc++.h"
using namespace std;
void insert_suitably(stack<int> &s,int x)
{
  if(s.empty() || x>s.top())
  {
    s.push(x);
    return;
  }
  int cur=s.top();
  s.pop();
  insert_suitably(s,x);
  s.push(cur);
}
void reverse(stack<int> &s)
{
  if (!s.empty())
  {
    int cur = s.top();
    s.pop();
    reverse(s);
    insert_suitably(s, cur);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  stack<int> s;
  s.push(3);
  s.push(4);
  s.push(1);
  s.push(2);
  reverse(s);
  while (!s.empty())
  {
    cout << s.top();
    s.pop();
  }
  return 0;
}