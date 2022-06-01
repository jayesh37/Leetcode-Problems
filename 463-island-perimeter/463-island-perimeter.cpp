class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans=0;
        
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,-1,1};
        
        for(int i=0; i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int count = 4;
                    
                    if(i!=0 && grid[i-1][j]==1)
                        count--;
                    if(j!=0 && grid[i][j-1]==1)
                        count--;
                    if(i!=m-1 && grid[i+1][j]==1)
                        count--;
                    if(j!=n-1 && grid[i][j+1]==1)
                        count--;
                    
                    ans += count;
                }
            }
        }
        return ans;
    }
};