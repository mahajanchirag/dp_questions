class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        // code here
        int dp[N];
        int best=1;
        dp[0]=1;
        for(int i=1;i<N;i++)
        {
            dp[i]=1;
            for(int j=i-1;j>=0;j--)
            {
                if(abs(A[j]-A[i])==1 )
                {
                    int possAns=dp[j];
                    if(dp[i]<possAns+1)
                    {
                        dp[i]=1+possAns;
                    }
                }
                
            }
            
            if(best<dp[i])
            {
                best=dp[i];
            }
        }
        return best;
    }
};
