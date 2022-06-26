class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int x = n-k;
        int sum = 0;
        int curr_sum = 0;
        int l=0 ,r=x;        
    
        for(int i=0;i<n;i++)    sum += cardPoints[i];        
        for(int i=0 ; i < x ;i++)   curr_sum += cardPoints[i];
    
        int ans = curr_sum;
        while(r<n)
        {
            curr_sum += cardPoints[r++]-cardPoints[l++];
            ans = min(curr_sum,ans);
            // cout<<curr_sum<<endl;
        }
        
        return sum - ans;
    }
};