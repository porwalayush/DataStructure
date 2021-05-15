// o(n) time o(1)space
// use kadane algo for find max and min subarray

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n=nums.size();
        int maxvalue=0,minvalue=0,total=0,tillmax=INT_MIN,tillmin=INT_MAX;
        for(int i=0;i<n;i++)
        {
            maxvalue+=nums[i];
            minvalue+=nums[i];
            tillmax=max(tillmax,maxvalue);
            tillmin=min(tillmin,minvalue);
            if(maxvalue<0)
            {
                maxvalue=0;
            }
            if(minvalue>0)
            {
                minvalue=0;
            }
            total+=nums[i];
        }
        if(total==tillmin)        // corner case when all elements are negative
            return tillmax;
        else
            return max(tillmax,total-tillmin);
    }
};