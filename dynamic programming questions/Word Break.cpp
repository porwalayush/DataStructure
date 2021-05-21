int wordBreak(string A, vector<string> &B) {
    //code here
    int n=A.length();
    set<string>hash;
    for(auto it:B)
    hash.insert(it);
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[n]=1;
    for(int i=n-1;i>=0;i--)
    {
        string tmp;
        for(int j=i;j<n;j++)
        {
            tmp.push_back(A[j]);
            if(hash.find(tmp)!=hash.end())
            {
                if(dp[j+1])
                dp[i]=1;
            }
        }
    }
    return dp[0];
}