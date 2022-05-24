class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n=s.size(), ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]==')')
            {
                if(!st.empty() && s[st.top()]=='(')
                {
                    st.pop();
                }
                else
                {
                    st.push(i);
                }
            }
            else
            {
                st.push(i);
            }
        }
        
        if(st.empty())
            return n;
        
        int a = n, b = 0;
        
        while(!st.empty())
        {
            b = st.top();
            st.pop();
            
            ans = max(ans,a-b-1);
            a=b;
        }
        
        return max(ans,a);
    }
};