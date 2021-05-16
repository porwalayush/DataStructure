class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int rows=word1.size();
        int cols=word2.size();
        int dp[rows+1][cols+1];
        dp[0][0]=0;
        for(int i=1;i<=cols;i++)
            dp[0][i]=i;
        for(int i=1;i<=rows;i++)
            dp[i][0]=i;
        
        for(int i=1;i<=rows;i++)
        {
            for(int j=1;j<=cols;j++)
            {
                if(word1[i-1]!=word2[j-1])
                    dp[i][j]=(min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1])))+1;
                    // min(insert,delete,replace)
                else
                    dp[i][j]=dp[i-1][j-1];
            }
        }
        return dp[rows][cols];
    }
};