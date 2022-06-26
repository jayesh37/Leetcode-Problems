class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int sum = 0,n=arr.size();
        int l = k-1,r = n-1;
        
        for(int i=0;i<k;i++)    sum += arr[i];
        
        int ans = sum;
        
        for(int i=0;i<k;i++)
        {
            sum += arr[r-i];
            sum -= arr[l-i];
            
            ans = max(sum,ans);
        }
        
        return ans;
    }
};