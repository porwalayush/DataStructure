    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(long long i=0;i<n;i++)
        {
            pq.push(arr[i]);
        }
        long long cost=0;
        while(pq.size()>1)
        {
            long long val1=pq.top();
            pq.pop();
            long long val2=pq.top();
            pq.pop();
            long long total=val1+val2;
            pq.push(total);
            cost+=total;
        }
        return cost;
    }