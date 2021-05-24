#include<bits/stdc++.h>
using namespace std;
vector<int> v;
void convertmaxheap(int cur)
{
	int par=cur/2;
	while(cur>1 and v[par]<v[cur])
	{
		swap(v[cur],v[par]);
		cur=par;
		par=par/2;
	}
	return;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;

	v.push_back(-1);
	while (cin >> n)
	{
		v.push_back(n);
	}

	// nlog(n)
	for(int cur=2;cur<v.size();cur++)
	{
		convertmaxheap(cur);
	}
	for(auto it:v)
		cout<<it<<" ";
	return 0;
}