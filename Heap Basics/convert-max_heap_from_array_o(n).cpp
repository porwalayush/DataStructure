#include<bits/stdc++.h>
using namespace std;
vector<int> v;
bool min_heap=false;
	bool compare(int a,int b)
	{
		if(min_heap)
		{
			return a<b;
		}
			return a>b;
	}
	void heapify(int par)
	{
		int left=2*par;
		int right=2*par+1;
		int min_index=par;
		int last=v.size();
		if(left<last and compare(v[left],v[par]))
			min_index=left;
		if(right<last and compare(v[right],v[min_index]))
			min_index=right;

		if(min_index!=par)
		{
			swap(v[min_index],v[par]);
			heapify(min_index);
		}
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

	for(int i=(v.size()-1)/2;i>0;i--)
	{
		heapify(i);
	}

	for(auto it:v)
		cout<<it<<" ";
	return 0;
}