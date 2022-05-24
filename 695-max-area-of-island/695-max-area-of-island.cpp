class Solution {
public:
    bool isSafe(vector<vector<int>> &grid,int i,int j)
    {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1;
    }
    
    int solve(vector<vector<int>> &grid,int i,int j)
    {
        if(isSafe(grid,i,j))
        {
            grid[i][j]=0;
            return 1+ solve(grid,i+1,j)+
                      solve(grid,i-1,j)+
                      solve(grid,i,j+1)+
                      solve(grid,i,j-1);
        }
        return 0;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int ans = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1)
                    ans = max(ans, solve(grid,i,j));
        
        return ans;
    }
};