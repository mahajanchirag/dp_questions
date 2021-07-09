class Solution{
  public:
  
    
  
    int minimumNumberOfDeletions(string s) { 
        // code here
       int n=s.length();
       string b=s;
       reverse(b.begin(),b.end());
       
       int dp[n+1][n+1];
       
       for(int i=0;i<n+1;i++)
       {
           for(int j=0;j<n+1;j++)
           {
               if(i==0 || j==0)
               {
                   dp[i][j]=0;
               }
               
               else if(s[i-1]==b[j-1])
               {
                   dp[i][j]=1+dp[i-1][j-1];
               }
               
               else
               {
                   dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
               }
               
           }
       }
       
       return n-dp[n][n];
       
    } 
};
