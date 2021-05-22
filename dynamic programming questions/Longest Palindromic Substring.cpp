class Solution {
public:
    string longestPalindrome(string s) {
        int size=s.length();
        int dp[size][size];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<size;i++)
            dp[i][i]=1;
        for(int j=0;j<size-1;j++)
            dp[j][j+1]=(s[j]==s[j+1])?1:0;
        for(int k=3;k<=size;k++)
        {
            for(int i=0;i+k-1<size;i++)
            {
                int j=i+k-1;
                if(s[i]==s[j])
                {
                    dp[i][j]=dp[i+1][j-1];
                }
            }
        }
        
        int mx=0,l,r;
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                if(dp[i][j] && j-i+1>mx)
                {
                    l=i;
                    r=j;
                    mx=j-i+1;
                }
            }
        }
        string fans;
        for(int i=l;i<=r;i++)
            fans.push_back(s[i]);
        return fans;
    }
};