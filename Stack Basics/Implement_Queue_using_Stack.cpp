// using two stack time complexity: O(n)
#include "bits/stdc++.h"
using namespace std;
class Queue
{
public:
    stack<int> s1,s2;
    void push(int ele)
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(ele);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int front()
    {
        return s1.top();
    }
    void pop()
    {
        s1.pop();
    }
};
int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    Queue q;
    q.push(1);
    q.push(3);
    q.push(2);
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    return 0;
}




// using two stack time complexity : O(1) amortized
#include "bits/stdc++.h"
using namespace std;
class Queue
{
public:
    stack<int> s1,s2;
    void push(int ele)
    {
        s1.push(ele);
    }
    int front()
    {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    void pop()
    {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }
};
int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    Queue q;
    q.push(1);
    q.push(3);
    q.push(2);
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    return 0;
}