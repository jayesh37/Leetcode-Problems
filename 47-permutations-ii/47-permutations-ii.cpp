class Solution {
public:
    vector<vector<int>>result;
    void permutation(vector<int>v,unordered_map<int,int>m,int n)
    {
        if(v.size() == n)
        {
            result.push_back(v);
            return;
        }
        for(auto it:m)
        {
            if(it.second == 0)
            {
                continue;
            }
           
                v.push_back(it.first);
                m[it.first]--;
            permutation(v,m,n);
            v.pop_back();
            m[it.first]++;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>m;
        for(auto it:nums)
        {
            m[it]++;
        }
        permutation(ans,m,nums.size());
        
        return result;
    }
};