class Solution {
public:
    
    
    
    int helper(int num,int n,vector<vector<int>> &v,vector<vector<int>> &dp)
    {
        if(n==1)
        {
            return dp[num][n]=1;
        }
        
        if(dp[num][n]!=-1)
        {
            return dp[num][n];
        }
        
        
        int ans=0;
        for(auto i:v[num])
        {
             ans=ans%1000000007+helper(i,n-1,v,dp)%1000000007;
        }
        return dp[num][n]=ans%1000000007;
        
    }
    int knightDialer(int n) {
        
        
        if(n==0)
        {
            return 0;
        }
        
         vector<vector<int>>v={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        vector<vector<int>> dp(10,vector<int>(n+1,-1));
        int ans=0;
        for(int i=0;i<10;i++)
        {
            int k=helper(i,n,v,dp)%1000000007;
            ans=ans%1000000007+k%1000000007;
        }
        
        return ans%1000000007;
    }
};
