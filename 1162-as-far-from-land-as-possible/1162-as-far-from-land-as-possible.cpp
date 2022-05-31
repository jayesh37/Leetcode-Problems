class Solution {
public:
    bool isValid(vector<vector<int>>& grid,int m,int n,int x,int y)
    {
        return x<m&&y<n&&x>=0&&y>=0&&grid[x][y]!=1;
    }
    
    int maxDistance(vector<vector<int>>& grid) 
    {
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        
        queue<pair<int,int>> q;
        int ans = 0;
        int m=grid.size(), n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty())
        {            
            int x = q.front().first;
            int y = q.front().second;
            for(int i=0;i<4;i++)
            {
                int nx=x + dx[i];
                int ny=y + dy[i];
                
                if(isValid(grid,m,n,nx,ny))
                {
                    if(grid[nx][ny]==0 || grid[nx][ny]>grid[x][y]+1)
                    {
                        q.push({nx,ny});
                        grid[nx][ny]=grid[x][y]+1;
                        
                        ans = max(ans,grid[nx][ny]);
                    }
                }
            }
            q.pop();
        }
        return ans-1;
    }
};