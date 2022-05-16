class Solution {
public:
    bool isSafe(int x,int y,int n,vector<vector<int>>& grid)
    {
        return x<n && y<n && x>=0 && y>=0 && grid[x][y]==0;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int dx[] = {0,0,1,-1,1,1,-1,-1};
        int dy[] = {1,-1,0,0,1,-1,1,-1};
        
        if(n==1)
            return 1;
        
        queue<pair<pair<int,int>,int>> q;
        if(grid[0][0]==0)
        {
            q.push({{0,0},1});
            grid[0][0]=1;
        }
        
        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            for(int i=0;i<8;i++)
            {
                int xc = x+dx[i];
                int yc = y+dy[i];

                if(isSafe(xc,yc,n,grid))
                {
                    q.push({{xc,yc},dist+1});
                    grid[xc][yc]=1;
                    
                    if(xc==n-1&&yc==n-1)
                        return dist+1;
                }
                
            }
        }
        return -1;
    }
};