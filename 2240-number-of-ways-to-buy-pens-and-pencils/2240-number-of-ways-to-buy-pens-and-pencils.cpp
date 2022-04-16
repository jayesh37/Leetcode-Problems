class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long int n= total/cost1;
        long long ans=0;
        
        for(long long i=0;i<=n;i++)
        {
            ans += (total/cost2) +1;
            total -= cost1;
        }
        return ans;
    }
};