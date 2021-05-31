#include "bits/stdc++.h"
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    set<int> s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
      int d;
      cin>>d;
      s.insert(d);
    }

    for(auto i=s.begin();i!=s.end();i++)
      cout<<*i<<" ";

    cout<<endl;
    s.erase(10);
    s.erase(s.find(16));

    for(auto it:s)
      cout<<it<<" ";

    auto lb=s.lower_bound(10);
    cout<<*lb<<endl;
    auto ub=s.upper_bound(18);
    cout<<*ub<<endl;


    set<pair<int,int>> sp;
    sp.insert(make_pair(5,10));
    sp.insert(make_pair(5,20));
    sp.insert(make_pair(6,18));
    sp.insert(make_pair(7,5));
    sp.insert(make_pair(1,50));

    for(auto it:sp)
      cout<<it.first<<"-"<<it.second<<endl; // sort acc to first value if first is same then second

    auto l=sp.lower_bound(make_pair(5,INT_MAX));  // return whose first value greater than 5
    cout<<(*l).first<<" "<<(*l).second;
    return 0;
}

//12
//10 5 10 18 5 3 4 19 11 1 16 6