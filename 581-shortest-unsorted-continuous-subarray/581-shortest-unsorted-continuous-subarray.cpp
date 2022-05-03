class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<pair<int,int>> v;
        
        for(int i=0;i<nums.size();i++)
        {
            v.push_back({nums[i],i});
        }
        
        sort(v.begin(),v.end());
        
        int start=nums.size()-1,end=0;
        
        for(int i=0;i<nums.size();i++)
        {   
            if(i!=v[i].second)
            {
                start= min(start,v[i].second);
                end = max(end,v[i].second);
            }
        }
        if(start>=end)
            return 0;
        return end-start+1;
    }
};