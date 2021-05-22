class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int size=s.length();
        string t=s;
        reverse(t.begin(),t.end());
        int dp[size+1][size+1];
        for(int i=0;i<=size;i++)
        {
            for(int j=0;j<=size;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else
                {
                    dp[i][j]=(s[i-1]!=t[j-1])?max(dp[i-1][j],dp[i][j-1]):1+dp[i-1][j-1];
                }
            }
        }
        return dp[size][size];
    }
};