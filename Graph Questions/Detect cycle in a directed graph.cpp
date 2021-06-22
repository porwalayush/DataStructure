class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool dfs(int cur,vector<int> *adj,vector<bool> &vis,vector<bool> &rec_stack)
	{
	    if(!vis[cur])
	    {
	        vis[cur]=rec_stack[cur]=true;
	        for(auto it:adj[cur])
	        {
	            if(!vis[it] && dfs(it,adj,vis,rec_stack))
	            return true;
	            else if(rec_stack[it])
	            return true;
	        }
	    }
	    rec_stack[cur]=false;
	    return false;
	}
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	bool ans=true;
	   	vector<bool> visited(V,false),rec_stack(V,false);
	   	for(int i=0;i<V;i++)
	   	{
	   	        if(dfs(i,adj,visited,rec_stack))
	   	        return true;
	   	}
	   	return false;
	}
};