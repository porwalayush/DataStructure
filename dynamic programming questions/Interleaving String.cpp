class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int rows=s1.length();
        int cols=s2.length();
        if(rows+cols!=s3.length()) return false;
        
        int dp[rows+1][cols+1];
        for(int i=0;i<=rows;i++)
        {
            for(int j=0;j<=cols;j++)
            {
                if(i==0 && j==0)
                    dp[i][j]=true;
                else if(i==0)
                {
                    dp[i][j]=dp[i][j-1] && s2[j-1]==s3[j-1];
                }
                else if(j==0)
                {
                    dp[i][j]=dp[i-1][j] && s1[i-1]==s3[i-1];
                }
                else
                {
                    dp[i][j]=(dp[i][j-1] && s2[j-1]==s3[i+j-1]) || (dp[i-1][j] && s1[i-1]==s3[i+j-1]);
                }
            }
        }
        return dp[rows][cols];
    }
};