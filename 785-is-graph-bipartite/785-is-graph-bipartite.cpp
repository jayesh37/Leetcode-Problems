class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(color[i]!=-1)
                continue;
            
            queue<int> pending;
            color[i]=0;
            pending.push(i);
            
            while(!pending.empty())
            {
                int parent = pending.front();
                pending.pop();

                for(auto child: graph[parent])
                {
                    if(color[child]==-1)
                    {
                        color[child] = 1-color[parent];
                        pending.push(child);
                    }
                    else if(color[child]==color[parent])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};