#include "bits/stdc++.h"
using namespace std;
class min_max_stack
{
private:
    vector<int> original;
    vector<int> max_stack;
    vector<int> min_stack;
public:
    void push(int ele)
    {
        int cur_min= ele;
        int cur_max= ele;
        if(original.size())
        {
            cur_min=min(min_stack[min_stack.size()-1],ele);
            cur_max=max(max_stack[max_stack.size()-1],ele);
        }
        max_stack.push_back(cur_max);
        min_stack.push_back(cur_min);
        original.push_back(ele);

    }
    void pop()
    {
        original.pop_back();
        max_stack.pop_back();
        min_stack.pop_back();
    }
    int top()
    {
        return original[original.size()-1];
    }
    int get_min()
    {
        return min_stack[min_stack.size()-1];
    }
    int get_max()
    {
        return max_stack[max_stack.size()-1];
    }
    bool empty()
    {
        return original.size()==0;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    min_max_stack s;
    s.push(11);
    s.push(10);
    s.push(15);
    s.push(100);
    s.push(1);
    cout<<s.get_max()<<" "<<s.get_min()<<endl;
    s.pop();
    cout<<s.get_max()<<" "<<s.get_min()<<endl;
    s.pop();
    cout<<s.get_max()<<" "<<s.get_min()<<endl;
    return 0;
}