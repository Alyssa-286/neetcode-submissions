class Solution {
public:
    bool dfs(int node,int parent, vector<vector<int>>&adj,vector<bool>&visited)
    {
        visited[node]=true;
        for(int neighb: adj[node])
        {
            if(!visited[neighb])
            {
                if(dfs(neighb,node,adj,visited))
                return true;
            }
            else if(neighb!=parent)
            return true;
        }
        
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1)
        return false;
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(dfs(0,-1,adj,visited))
        return false;
          for(int i=0;i<n;i++)
        {
            if(!visited[i])
            return false;
        }
        return true;


    }
};
