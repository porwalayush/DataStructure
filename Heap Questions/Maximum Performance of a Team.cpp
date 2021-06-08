class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
            v.push_back(make_pair(efficiency[i],speed[i]));
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        priority_queue<int,vector<int>,greater<int>> pq;
        long long cur_sum=0,ans=0;
        for(int i=0;i<n;i++)
        {
            if(pq.size()>k-1)
            {
                int cur=pq.top();
                cur_sum-=cur;
                pq.pop();
            }
            cur_sum+=(v[i].second);
            pq.push(v[i].second);
            ans=max(ans,cur_sum*v[i].first);
        }
        return ans%1000000007;
    }
};