typedef pair<int,pair<int,int>> node;
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> ans;
        priority_queue<node,vector<node>,greater<node>> pq;
        for(int i=0;i<K;i++)
        {
            node temp;
            pq.push({arr[i][0],{i,0}});
        }
        while(!pq.empty())
        {
            node tmp=pq.top();
            pq.pop();
            ans.push_back(tmp.first);
            int x=tmp.second.first;
            int y=tmp.second.second;
            if(y+1<K)
            pq.push({arr[x][y+1],{x,y+1}});
        }
        return ans;
    }
};