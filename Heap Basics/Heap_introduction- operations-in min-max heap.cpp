#include<bits/stdc++.h>
using namespace std;

class heap
{
	vector<int>v;
	bool min_heap;
	bool compare(int a,int b)
	{
		if(min_heap)
		{
			return a<b;
		}
		else
		{
			return a>b;
		}
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
public:
	heap(int default_size=10,bool mn=true)
	{
		v.reserve(default_size);
		v.push_back(-1);
		min_heap=mn;
	}

	void push(int element)
	{
		v.push_back(element);
		int cur=v.size()-1;
		int par=cur/2;
		while(cur>1 and compare(v[cur],v[par]))
		{
			swap(v[cur],v[par]);
			cur=par;
			par=par/2;
		}
	}

	int get()
	{
		return v[1];
	}

	void pop()
	{
		swap(v[1],v[v.size()-1]);
		v.pop_back();
		heapify(1);
	}
	bool isempty()
	{
		return v.size()==1;
	}
};
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	heap h;        // by default min heap
	// heap h(10,false);     for max heap
	int n;
	while(cin>>n)
	{
		h.push(n);
	}
	while(!h.isempty())
	{
		cout<<h.get()<<" ";
		h.pop();
	}
	return 0;
}