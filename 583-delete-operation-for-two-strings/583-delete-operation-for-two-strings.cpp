class Solution {
public:
    int dp[501][501];
    
    int getlcs(string x,string y,int n,int m)
    {
        if(n==0||m==0)
            return dp[n][m]=0;
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        if(x[n-1]==y[m-1])
            return dp[n][m] = 1 + getlcs(x,y,n-1,m-1);
        
        else
            return dp[n][m] = max(getlcs(x,y,n-1,m) , getlcs(x,y,n,m-1));
    }
    
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        
        int n = word1.size();
        int m = word2.size();
        int ans = getlcs(word1,word2,n,m);
        
        return n+m-2*ans;
    }
};