class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto it:nums)
        {
            pq.push(it);
        }
        k=k-1;
        while(k--)
        {
            pq.pop();
        }
        return pq.top();
    }
};