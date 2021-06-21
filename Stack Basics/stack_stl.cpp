#include "bits/stdc++.h"
using namespace std;
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
    while(!s.empty())
    {
        int tp=s.top();
        s.pop();
        cout<<tp<<" ";
    }
    return 0;
}