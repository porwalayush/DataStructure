space complexity: O(n*n)

typedef pair<int,pair<int,int>> node;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int visited[rows][cols];
        memset(visited,0,sizeof(visited));
        priority_queue<node,vector<node>,greater<node>> pq;
        pq.push({matrix[0][0],{0,0}});
        visited[0][0]=1;
        k=k-1;
        while(!pq.empty() && k>0)
        {
            node cur=pq.top();
            pq.pop();
            if(cur.second.first+1<rows && !visited[cur.second.first+1][cur.second.second])
            {
                pq.push({matrix[cur.second.first+1][cur.second.second],{cur.second.first+1,cur.second.second}});
                visited[cur.second.first+1][cur.second.second]=1;
            }
            if(cur.second.second+1<cols && !visited[cur.second.first][cur.second.second+1])
            {
                pq.push({matrix[cur.second.first][cur.second.second+1],{cur.second.first,cur.second.second+1}});
                visited[cur.second.first][cur.second.second+1]=1;
            }
            k--;
        }
        return pq.top().first;
    }
};

space complexity: o(n)

typedef pair<int,pair<int,int>> node;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        priority_queue<node,vector<node>,greater<node>> pq;
        for(int i=0;i<cols;i++)
        {
            pq.push({matrix[0][i],{0,i}});
        }
        k=k-1;
        while(!pq.empty() && k>0)
        {
            node cur=pq.top();
            pq.pop();
            if(cur.second.first+1<rows)
            {
                pq.push({matrix[cur.second.first+1][cur.second.second],{cur.second.first+1,cur.second.second}});
            }
            k--;
        }
        return pq.top().first;
    }
};