#include "bits/stdc++.h"
using namespace std;
void insert_at_bottom(stack<int> &s,int ele)
{
    if(s.size()==0)
    {
        s.push(ele);
        return;
    }
    int tp=s.top();
    s.pop();
    insert_at_bottom(s,ele);
    s.push(tp);
}
void reverse(stack<int> &s)
{
    if(s.size()==0)
        return;
    int cur=s.top();
    s.pop();
    reverse(s);
    insert_at_bottom(s,cur);
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