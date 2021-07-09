class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size=nums.size();
        vector<int>temp(size,1);
        int max_len=1;
        
        for(int i=1;i<size;i++)
        {
            for(int j=0;j<i;j++)
            {
                if( nums[j]<nums[i])
                {
                    if(temp[i]<=temp[j])
                    {
                        temp[i]=temp[j]+1;
                        max_len=max(max_len,temp[i]);
                    }
                }
            }
        }
        return max_len;
    }
};
