class Solution {
public:
        
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int n = s.size();
        set<char> st;
        int ans= 0;
        for(int r=0;r<n;r++)
        {
            while(st.find(s[r])!=st.end())
            {
                st.erase(s[l++]);
            }
            st.insert(s[r]);
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};