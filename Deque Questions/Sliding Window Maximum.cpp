class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i;
        deque<int> f;
        for(i=0;i<k;i++)
        {
            while(!f.empty() && nums[i]>=nums[f.back()])
                f.pop_back();
            f.push_back(i);
        }
        vector<int> v;
        for(;i<nums.size();i++)
        {
            v.push_back(nums[f.front()]);
            
            while(!f.empty()  && f.front()<=i-k)
                f.pop_front();
            
            while(!f.empty() && nums[i]>=nums[f.back()])
                f.pop_back();
            f.push_back(i);
        }
v.push_back(nums[f.front()]);
        return v;
    }
};