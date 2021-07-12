class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        
        int dp[n][m];
        int ans=0;
        for(int j=0;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(j==0)
                {
                    dp[i][j]=M[i][j];
                }
                
                else
                {
                    dp[i][j]=dp[i][j-1];
                    if(i-1>=0)
                    {
                        dp[i][j]=max(dp[i-1][j-1],dp[i][j]);
                    }
                    
                    if(i+1<n)
                    {
                        dp[i][j]=max(dp[i][j],dp[i+1][j-1]);
                    }
                    dp[i][j]=M[i][j]+dp[i][j];
                    
                }
                
                ans=max(ans,dp[i][j]);
            }
  
            
        }
        
        
        
        
        return ans;
    }
};
