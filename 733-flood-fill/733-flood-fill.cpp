class Solution {
public:
    bool isSafe(int x,int y,int m,int n)
    {
        return x>=0 && y>=0 && x<m && y<n;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int oldColor = image[sr][sc];
        
        dfs(image,sr,sc,oldColor,newColor);
        
        return image;
    }
    
    void dfs(vector<vector<int>> &image,int x,int y,int oldColor,int newColor)
    {
        int m= image.size(), n= image[0].size();
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,-1,1};
        
        if(!isSafe(x,y,m,n))
            return;
        
        if(image[x][y] != oldColor || image[x][y] == newColor)
            return;
        
        image[x][y] = newColor;
        
        for(int i=0;i<4;i++)
            dfs(image,x+dx[i],y+dy[i],oldColor,newColor);
    }
};