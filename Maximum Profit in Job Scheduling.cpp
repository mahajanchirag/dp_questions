class Solution {
public:

//USING DP AND BINARY SEARCH
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int> > ans;
        vector<int> dp;
        for(int i=0;i<n;i++)
        {
            ans.push_back({endTime[i],startTime[i],profit[i]});
        }
        sort(ans.begin(),ans.end()); // sort using end time
		
        dp.push_back(ans[0][2]);
        int index,temp;
        for(int i=1;i<n;i++)
        {
            index=-1;
//             Using Linear Search O(n^2)
//             for(int j=i-1;j>=0;j--)
//             {
//                 if(ans[j][0]<=ans[i][1])
//                 {
//                     index = j;
//                     break;
//                 }
//             }
            
//             Using Binary Search O(nlogn)
             int l=0,h=i-1;
            while(l<=h)
           {
                int m = (l+h)/2;
                if(ans[m][0]<=ans[i][1])
                {
                    if (ans[m+1][0] <= ans[i][1]) 
                         l = m + 1; 
                     else
                     {
                        index = m;
                         break;
                     } 
                 }
                 else
                     h = m-1;
             }
            
            if(index!=-1)
                temp = dp[index] + ans[i][2];
            else temp = ans[i][2];
            dp.push_back(max(temp,dp[i-1]));
        }
        
        return dp[n-1];
    }
};
