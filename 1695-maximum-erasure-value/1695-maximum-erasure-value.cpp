class Solution {
public:
    /*
    
    Move right pointer if we find that element already present
    and keep adding it to sum
    
    If an element is already present start removing all elements till
    the repeated element present
    
    */
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> m; // last occuring index of element 
        int l=0,sum=0,ans=0,n=nums.size();
        
        for(int r=0;r<n;r++)
        {
            int x = nums[r];
            
            if(m.find(x)!=m.end())  //if already present
            {
                int index = m[x];
                while(l<=index)
                {
                    m.erase(nums[l]);
                    sum -= nums[l];
                    l++;
                }
            }
            m[x]=r;
            sum += x;
            ans = max(ans,sum);
        }
        
        return ans;
    }
};