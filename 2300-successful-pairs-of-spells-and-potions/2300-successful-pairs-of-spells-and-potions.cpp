class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)     {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        
        for(auto x : spells)
        {
            long require = ceil((success*1.0)/x);
            auto index = lower_bound(potions.begin(),potions.end(),require);
            ans.push_back(potions.end()-index);
        }
        
        return ans;
    }
};