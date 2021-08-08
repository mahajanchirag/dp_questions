class Solution {
public:
    int dp[5001][301];
    int helper(int amount, vector<int>& coins,int n)
    {
        if(n<=0 || amount<0 )
        {
            return 0;
        }
        
        if(amount==0)
        {
            return 1;
        }
        
        
        if(dp[amount][n]!=-1)
        {
            return dp[amount][n];
        }
        
        
        return dp[amount][n]=helper(amount-coins[n-1],coins,n)+helper(amount,coins,n-1);
        
    }
    
    
    int change(int amount, vector<int>& coins) {
        
        
       memset(dp,-1,sizeof(dp));
        
        return helper(amount,coins,coins.size());
        
        
    }
};
