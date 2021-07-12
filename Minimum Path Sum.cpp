class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        int dp[m][n],a,b;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=grid[i][j];
                }
                
                else
                {
                    if(i-1>=0)
                    {
                         a=dp[i-1][j];
                    }
                    else
                    {
                        a=INT_MAX;
                    }
                    
                     if(j-1>=0)
                    {
                         b=dp[i][j-1];
                    }
                    else
                    {
                        b=INT_MAX;
                    }
                    
                    dp[i][j]=grid[i][j]+min(a,b);
                }
                
            }
            
            
        }
        return dp[m-1][n-1];
    }
};
