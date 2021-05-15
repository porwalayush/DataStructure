class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        int rows=nums1.size();
        int cols=nums2.size();
        int dp[rows+1][cols+1];
        for(int i=0;i<=rows;i++)
        {
            for(int j=0;j<=cols;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(nums1[i-1]==nums2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[rows][cols];
    }
};