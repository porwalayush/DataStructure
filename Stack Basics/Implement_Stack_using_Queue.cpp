// using 2 queues
#include "bits/stdc++.h"
using namespace std;
class Stack
{
public:
    queue<int> q1,q2;
    void push(int ele)
    {
        q2.push(ele);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> tmp;
        tmp=q2;
        q2=q1;
        q1=tmp;
    }
    int top()
    {
        return q1.front();
    }
    void pop()
    {
        q1.pop();
    }
};
int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    Stack s;
    s.push(3);
    s.push(4); 
    s.push(5); 
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    return 0;
}




//using 1 queue

#include "bits/stdc++.h"
using namespace std;
class Stack
{
public:
    queue<int> q;
    void push(int ele)
    {
        q.push(ele);
        int sz=q.size()-1;
        for(int i=0;i<sz;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    int top()
    {
        return q.front();
    }
    void pop()
    {
        q.pop();
    }
};
int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    Stack s;
    s.push(3);
    s.push(4); 
    s.push(5); 
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    return 0;
}