int dp[501][501];
    
    bool ispalindrome(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string str,int i,int j){
        if(i>=j){
            return 0;
        }
        if(ispalindrome(str,i,j)){
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=INT_MAX,left,right;
        for(int k=i;k<j;k++){
            if(dp[i][k]!=-1) left=dp[i][k];
            else{
                left=solve(str,i,k);
                dp[i][k]=left;
            }
            
            if(dp[k+1][j]!=-1) right=dp[k+1][j];
            else{
                right=solve(str,k+1,j);
                dp[k+1][j]=right;
            }
            int temp=left+right+1;
            
            ans=min(ans,temp);
            
        }
        dp[i][j]=ans;
        return ans;
    }
    
   



int Solution::minCut(string A) {
    memset(dp,-1,sizeof(dp));
    return solve(A,0,A.length()-1);
}
