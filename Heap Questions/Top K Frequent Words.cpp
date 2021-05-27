class Solution {
public:
    class cmp
    {
      public:
        bool operator()(pair<int,string> a, pair<int,string> b)
        {
            if(a.first!=b.first)
                return a.first<b.first;
            return a.second>b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        for(auto it:words)
            m[it]++;
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
        for(auto it:m)
        {
            pq.push({it.second,it.first});
        }
        
    
        vector<string> ans;
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};