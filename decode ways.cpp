class Solution {
public:
    
    
    int helper(string &s,int i,vector<int> &dp)
    {
        if(i>=s.length())
        {
            return 1;
        }
        
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        if(s[i]=='0')
        {
            return dp[i]=0;
        }
        
        
        int ans1=0,ans2=0;
        
        ans1=helper(s,i+1,dp);
        
        
        if(i+1<s.length() && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6')) )
        {
            ans2=helper(s,i+2,dp);
        }
        
        return dp[i]=ans1+ans2;
    }
    
    
    int numDecodings(string s) {
        
       vector<int> dp(s.length()+1,-1); 
       return helper(s,0,dp);
    }
};
