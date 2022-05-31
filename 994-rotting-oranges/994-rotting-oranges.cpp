class Solution {
public:
    
    bool isValid(vector<vector<int>> &grid,int m,int n,int x,int y)
    {
        return x<m && y<n && x>=0 && y>=0 && grid[x][y]==1;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m=grid.size(),n=grid[0].size();
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        int fresh=0;
        
        int ans = -1;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        
        while(!q.empty())
        {
            int len = q.size();
            
            for(int i=0;i<len;i++)
            {
                int x= q.front().first;
                int y= q.front().second;
                q.pop();
                
                for(int j=0;j<4;j++)
                {
                    if(isValid(grid,m,n,x+dx[j],y+dy[j]))
                    {
                        q.push({x+dx[j],y+dy[j]});
                        grid[x+dx[j]][y+dy[j]]=2;
                        fresh--;
                    }
                }
            }
            ans++;
        }
        
        if(fresh>0) return -1;
        if(ans==-1) return 0;
        
        return ans;
    }
};