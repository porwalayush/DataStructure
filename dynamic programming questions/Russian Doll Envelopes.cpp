//prerequisite : LIS

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        int dp[n];
        for(int i=0;i<n;i++)
            dp[i]=1;
        sort(envelopes.begin(),envelopes.end());   //sort acc to assending height and width 
        // for(int i=0;i<n;i++)
        //     cout<<envelopes[i][0]<<" "<<envelopes[i][1]<<endl;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(envelopes[i][0]>envelopes[j][0]
                  && envelopes[i][1]>envelopes[j][1]
                  && dp[i]<dp[j]+1)
                    dp[i]=dp[j]+1;
            }
        }
        int mx=0;
        for(int i=0;i<n;i++)
            mx=max(mx,dp[i]);
        return mx;
    }
};