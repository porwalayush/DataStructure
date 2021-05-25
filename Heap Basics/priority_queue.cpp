#include<bits/stdc++.h>
using namespace std;
int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

    //priority_queue<int> pq;   // by default max heap
    priority_queue<int,vector<int>,greater<int>> pq;   // min heap
    pq.push(10);
    pq.push(9);
    pq.push(1);
    pq.push(11);
    pq.push(7);

    while(!pq.empty())
    {
      cout<<pq.top()<<" ";
      pq.pop();
    }
    return 0;
}