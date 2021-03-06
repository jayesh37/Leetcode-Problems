class Solution {
public:
    
    int getSum(vector<int> &nums,int n)
    {
        int sum=0;
        for(int i=0;i<n;i++)    sum += nums[i];
        
        return sum;
    }
    
    int minOperations(vector<int>& nums, int x) {
        int l=0,ans= -1,n=nums.size();
        int curr_sum=0;
        
        int sum = getSum(nums,n);
        
        for(int r=0;r<n;r++)
        {
            curr_sum += nums[r];
            
            while(l<=r && curr_sum>sum-x)
                curr_sum -= nums[l++];
            
            if(curr_sum == sum-x)
                ans = max(ans,r-l+1);
        }
        
        if(ans==-1) return ans;
        
        return n-ans;
    }
};