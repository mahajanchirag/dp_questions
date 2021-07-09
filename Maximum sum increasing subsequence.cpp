	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    
	    int dp[n];
	    int best=arr[0];
	    dp[0]=arr[0];
	    
	    for(int i=1;i<n;i++)
	    {
	        dp[i]=arr[i];
	        for(int j=i-1;j>=0;j--)
	        {
	            if(arr[j]<arr[i])
	            {
	                dp[i]=max(dp[i],arr[i]+dp[j]);
	            }
	        }
	        
	        best=max(best,dp[i]);
	    }
	    return best;
	}  
