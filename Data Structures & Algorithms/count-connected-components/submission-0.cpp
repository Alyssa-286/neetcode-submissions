class Solution {
public:
     void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited)
    {
        visited[node]=true;
        for(int neighb: adj[node])
        {
            if(!visited[neighb])
            {
                dfs(neighb,adj,visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int components=0;
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            components++;
            dfs(i,adj,visited);

        }
        
        return components;

    }
};
