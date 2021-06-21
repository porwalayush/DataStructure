#include<iostream>
#include<vector>
using namespace std;


template<typename T>
class stack
{
private:
    vector<T> v;
public:
    void push(T val)
    {
        v.push_back(val);
    }
    bool empty()
    {
        return v.size()==0;
    }
    void pop()
    {
        if(!empty())
            v.pop_back();
    }
    T top()
    {
        return v[v.size()-1];
    }
};


int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif


    stack<string> s;
    s.push("ayush");
    s.push("ramesh");
    s.push("seeta");
    s.push("geeta");
    while(!s.empty())
    {
        string tp=s.top();
        s.pop();
        cout<<tp<<" ";
    }



    return 0;
}