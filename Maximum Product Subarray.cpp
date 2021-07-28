class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        
        int best=INT_MIN;
        int ma_pr=1;
        int mi_pr=1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                swap(ma_pr,mi_pr);
            }
            
            
            ma_pr=max(ma_pr*nums[i],nums[i]);
            mi_pr=min(mi_pr*nums[i],nums[i]);
            
            best=max(ma_pr,best);
            
        }
        
        return best;
        
    }
};
