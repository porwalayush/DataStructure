// we can use two stack: first , second and do the following
// current->first
// first->second
// second->current 
// current stack is reversed...  time complexity O(n)

// but what if we can use only one extra stack???? 
// time complexity O(N*N)
#include "bits/stdc++.h"
using namespace std;
void shift(stack<int> &a ,stack<int> &b,int tot)
{
    while(tot--)
    {
        int tp=a.top();
        a.pop();
        b.push(tp);
    }
}
void reverse(stack<int> &s)
{
  stack<int> helper;
  int n=s.size();

  for(int i=0;i<n;i++)
  {
    int x=s.top();
    s.pop();
    //n-i-1 elements shift to helper
    shift(s,helper,n-i-1);
    // push x in s
    s.push(x);
    //reshift n-i-1 elements to s
    shift(helper,s,n-i-1);
  }  
}
int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif
    
    stack<int> s;
    s.push(1);
    s.push(152);
    s.push(122);
    s.push(17);
    s.push(6);
    reverse(s);
    while(!s.empty())
    {
        int tp=s.top();
        s.pop();
        cout<<tp<<" ";
    }
    return 0;
}