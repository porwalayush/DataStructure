class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	stack<int> path;
	void dfs(int cur,vector<int> *adj,vector<bool> &visited)
	{
	    visited[cur]=true;
	    for(auto it:adj[cur])
	    {
	        if(!visited[it])
	        {
	            dfs(it,adj,visited);
	        }
	    }
	    path.push(cur);
	}
	void dfs2(int cur,vector<int> *reverse,vector<bool> &visited)
	{
	    visited[cur]=true;
	    for(auto it:reverse[cur])
	    {
	        if(!visited[it])
	        {
	            dfs(it,reverse,visited);
	        }
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited);
            }
        }
        for(int i=0;i<V;i++)
        visited[i]=false;
        vector<int> reverse[V];
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                reverse[it].push_back(i);
            }
        }
        int ans=0;
        while(!path.empty())
        {
            int tp=path.top();
            path.pop();
            if(!visited[tp])
            {
                dfs2(tp,reverse,visited);
                ans++;
            }
        }
        return ans;
    }
};