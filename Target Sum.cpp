class Solution {
public:
    
 int CountSubsets(vector<int> &arr,int Sum,int n)
    {
       int t[n+1][Sum+1]; // 2D array for storing subproblems result

       // Base Case initialization
       for(int j=0;j<Sum+1;++j)
        t[0][j] = 0; // subset sum is not possible for empty array

       // for(int i=0;i<n+1;++i)
       //  t[i][0] = 1; // Zero sum possible for empty subset
       
       t[0][0] = 1; // Zero sum possible for empty subset
        
       for(int i=1;i<n+1;++i)
        if(arr[i-1]==0)
        {
            // For sum 0, Empty subset + subset made by 0 element
            // By multiplying pow(2,cnt), it will consider all the subsets of 0 which was               
			// not considered earlier.
            t[i][0]=2*t[i-1][0]; 
        }
                
        else
        {
             t[i][0]=t[i-1][0];
        }

       for(int i=1;i<n+1;++i)
        for(int j=1;j<Sum+1;++j)
        {
            if(arr[i-1] <= j)
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            else if(arr[i-1] > j)
                t[i][j] = t[i-1][j];
        }

       return t[n][Sum];
    } 
    
    
    
    int findTargetSumWays(vector<int>& nums, int S) {
        
        
        int SumOfNums = 0;
        
        for(int i=0;i<nums.size();++i)
            SumOfNums = SumOfNums + nums[i];
        
        // Here S is actually difference
        
        // We would never get the difference S by partitioning the array into two subsets. 
        if(SumOfNums < S || (SumOfNums + S)%2 != 0 ) 
            return 0;
        
        int SumOfS1 = (SumOfNums + S) / 2; //Derived from formula described at start of code
        
        int n = nums.size();
        
        return CountSubsets(nums,SumOfS1,n); 
        
    }
};
