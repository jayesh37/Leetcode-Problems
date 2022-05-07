class Solution {
public:
    /*
    
    stack = 4  
    
    third_element = 2
    
    nums= 3 1 4 2
    
    
    */
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        
        int thirdElement = INT_MIN;
        int n= nums.size();
        
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] < thirdElement) 
                return true;
            
            while(!st.empty() && st.top() < nums[i]) {
                thirdElement = st.top();
                st.pop();
            }
            
            st.push(nums[i]);
        }
        
        return false;
    }
};