// min stack O(1) extra space
#include<bits/stdc++.h>
using namespace std;
class min_stack
{
private:
  stack<int> s;
  int cur_min;
public:
  void push(int x)
  {
    if (s.empty())
    {
      s.push(x);
      cur_min = x;
      return;
    }
    if (x >= cur_min)
    {
      s.push(x);
    }
    else
    {
      s.push(2 * x - cur_min);
      cur_min = x;
    }
  }
  void pop()
  {
    if (s.top() < cur_min)
    {
      cur_min = 2 * cur_min - s.top();
    }
    s.pop();
  }
  int top()
  {
    return (cur_min > s.top()) ? cur_min : s.top();
  }
  int get_min()
  {
    return cur_min;
  }
};
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  min_stack s;
  s.push(20);
  cout << s.get_min() << endl;
  s.push(10);
  cout << s.get_min() << endl;
  s.push(25);
  cout << s.get_min() << endl;
  s.push(2);
  cout << s.get_min() << endl;
  s.push(12);
  cout << s.get_min() << endl;
  s.pop();
  cout << s.get_min() << endl;
  s.pop();
  cout << s.get_min() << endl;
  s.pop();
  cout << s.get_min() << endl;
  s.pop();
  cout << s.get_min() << endl;
  return 0;
}