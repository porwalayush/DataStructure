class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> num;  // padded array
        num.push_back(1);
        for(auto it:nums)
            num.push_back(it);
        num.push_back(1);
        int dp[600][600];
        int n=nums.size();
        memset(dp,0,sizeof(dp));
        for(int window_size=1;window_size<=n;window_size++)  // calculate smaller window problem first
        {
            for(int left=1;left<=n-window_size+1;left++)
            {
                int right=left+window_size-1;
                for(int last_element=left;last_element<=right;last_element++)
                {
                    dp[left][right]=max(dp[left][right],num[left-1]*num[last_element]*num[right+1]+dp[left][last_element-1]+dp[last_element+1][right]);
                }
            }
        }
        return dp[1][n];
    }
};