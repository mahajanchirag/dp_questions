class Solution {
public:
    int countSubstrings(string s) {
        
        
        bool dp[s.length()][s.length()];
        memset(dp,false,sizeof(dp));
        int count=0;
        
        for(int i=0;i<s.length();i++)
        {
            dp[i][i]=true;
            count++;
            
        }
        
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=true;
                count++;
            }
        }
        
        
        for(int gap=3;gap<=s.length();gap++)
        {
            for(int i=0;i<s.length()-gap+1;i++)
            {
                int j=i+gap-1;
                
                if(dp[i+1][j-1]==true && s[i]==s[j])
                {
                    dp[i][j]=true;
                    count++;
                }
            }
        }
        return count;
    }
};
