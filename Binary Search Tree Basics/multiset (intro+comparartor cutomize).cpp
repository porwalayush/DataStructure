#include "bits/stdc++.h"
using namespace std;
class compare
{
public:
  bool operator()(pair<string,int> a,pair<string,int> b)
  {
    return a.second<b.second;
  }
};
int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    multiset<int> s;   // stores duplicate also
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
    cout<<s.count(10)<<endl;

    auto m = s.equal_range(10);  // return iterator from first occ till last occ
    for(auto i=m.first;i!=m.second;i++)
      cout<<*i<<" ";
    cout<<endl;


    for(auto it=s.lower_bound(5);it!=s.upper_bound(18);it++)  //print all element >=5 and <18
       cout<<*it<<" ";
    cout<<endl;



    multiset<pair<string,int>,compare> mp;
    mp.insert(make_pair("ayush",10));
    mp.insert(make_pair("porwal",20));
    mp.insert(make_pair("ayushi",30));
    mp.insert(make_pair("ramesh",5));
    mp.insert(make_pair("payal",1));


    for(auto it:mp)
      cout<<it.first<<"->"<<it.second<<endl;
    return 0;
}

//12
//10 5 10 18 5 3 4 19 11 1 16 6