class Solution {
public:
    
    int solve(vector<int> &prices,int index,int buying,vector<vector<int>> &dp)
    {
        if(index==prices.size())
            return 0;
        
        if(dp[index][buying]!=-1)
            return dp[index][buying];
        
        if(buying)
        {
            int buy = -prices[index] + solve(prices,index+1,0,dp);
            int notbuy = solve(prices,index+1,1,dp);
                
            return dp[index][buying]=max(buy,notbuy);
        }
        else
        {
            int sell = prices[index] + solve(prices,index+1,1,dp);
            int notsell = solve(prices,index+1,0,dp);
            
            return dp[index][buying] = max(sell,notsell);
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int buying = 1;
        int index = 0;
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        
        return solve(prices,index,buying,dp);
    }
};