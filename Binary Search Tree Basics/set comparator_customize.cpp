#include "bits/stdc++.h"
using namespace std;
class compare
{
public:
  bool operator()(int a,int b)
  {
    return a>b;
  }
};
int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    set<int,compare> s;   // stores duplicate also
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
      int d;
      cin>>d;
      s.insert(d);
    }

    for(auto it:s)
      cout<<it<<" ";
    return 0;
}

//12
//10 5 10 18 5 3 4 19 11 1 16 6