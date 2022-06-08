class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.empty())
            return 0;
        
        int l=0,r=s.size()-1;
        while(l<r)
        {
            if(s[l]==s[r])
            {
                l++;
                r--;
            }
            else
            {
                return 2;
            }
        }
        return 1;
    }
};