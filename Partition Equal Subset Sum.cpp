class Solution {
public:
    
    
    bool solve(vector<int>& nums,int n,int total,int sum,vector<vector<int>> &dp)
    {
        if(n==0)
        {
            return false;
        }
        
        if(total==sum)
        {
            return true;
        }
        
        if(dp[n][total]!=-1)
        {
            return dp[n][total];
        }
        
        bool k=solve(nums,n-1,total+nums[n-1],sum,dp)||solve(nums,n-1,total,sum,dp);
        
        return dp[n][total]=k;
        
        
        
            
    }
    
    
    
    
    bool canPartition(vector<int>& nums) {
        
        if(nums.size()==0)
        {
            return false;
        }
        
        
        int sum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
        }
        
        if(sum%2!=0)
        {
            return false;
        }
        
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum+1,-1));
        
        sum=sum/2;
        
        return solve(nums,nums.size(),0,sum,dp);
        
    }
};
