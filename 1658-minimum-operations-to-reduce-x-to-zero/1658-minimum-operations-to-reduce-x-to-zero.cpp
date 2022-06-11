class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int l=0,ans= -1,n=nums.size();
        int sum=0,curr_sum=0;
        
        for(int i=0;i<n;i++)    sum += nums[i];
        
        if(x>sum)   return -1;
        
        sum -= x;
        
        for(int r=0;r<n;r++)
        {
            curr_sum += nums[r];
            while(l<=r && curr_sum>sum)
            {
                curr_sum -= nums[l++];
            }
            
            
            if(curr_sum == sum)
            {
                ans = max(ans,r-l+1);
            }
        }
        
        if(ans==-1)
            return ans;
        
        return n-ans;
    }
};