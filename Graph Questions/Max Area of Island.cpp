class Solution {
public:
    bool visited[51][51];
    void dfs_helper(vector<vector<int>>& grid,int &count,int i,int j)
    {
        visited[i][j]=true;
        int rows=grid.size();
        int cols=grid[0].size();
        if(i+1<rows && grid[i+1][j]==1 && !visited[i+1][j])
        {
            count+=1;
            dfs_helper(grid,count,i+1,j);
        }
        if(i-1>=0 && grid[i-1][j]==1 && !visited[i-1][j])
        {
            count+=1;
            dfs_helper(grid,count,i-1,j);
        }
        if(j+1<cols && grid[i][j+1]==1 && !visited[i][j+1])
        {
            count+=1;
            dfs_helper(grid,count,i,j+1);
        }
        if(j-1>=0 && grid[i][j-1]==1 && !visited[i][j-1])
        {
            count+=1;
            dfs_helper(grid,count,i,j-1);
        }
        return ;
    }
    int dfs(vector<vector<int>>& grid)
    {
        int rows=grid.size();
        int cols=grid[0].size();
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                visited[i][j]=false;
            }
        }
        int mx=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                {
                    int count=1;
                    dfs_helper(grid,count,i,j);
                    mx=max(mx,count);
                }
            }
        }
        return mx;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        return dfs(grid);
    }
};