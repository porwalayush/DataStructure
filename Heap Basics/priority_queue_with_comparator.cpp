#include<bits/stdc++.h>
using namespace std;
class person
{
public:
  string name;
  int age;
};
class comparator
{
public:
  bool operator()(person A,person B)
  {
    return A.age<B.age;  // return oldest 
  }
};
int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

    priority_queue<person,vector<person>,comparator> pq;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
      person p;
      cin>>p.name>>p.age;
      pq.push(p);
    }

    for(int i=1;i<=3;i++)
    {
      cout<<pq.top().name<<endl;
      pq.pop();
    }

    return 0;
}


/*

5
A 10
B 20
C 30
D 1
E 5

*/