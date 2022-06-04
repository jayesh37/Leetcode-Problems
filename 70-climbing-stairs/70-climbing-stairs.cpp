class Solution {
public:
    int arr[46];
    
    int solve(int n)
    {
        if(n==1||n==2)
            return arr[n]=n;
        
        if(arr[n]!=-1)
            return arr[n];
        
        return arr[n] = solve(n-1) + solve(n-2);
    }
    
    int climbStairs(int n) {
        memset(arr,-1,sizeof(arr));
        arr[0]=0;
        
        return solve(n);
    }
};