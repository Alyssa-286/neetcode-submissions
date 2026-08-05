class Solution {
public:
    bool canreach(int cur,int target,vector<vector<int>> &adj,vector<bool>& visited)
    {
        if(cur==target)
        return true;
        visited[cur]=true;
        for(auto neib: adj[cur])
        {
            if(!visited[neib])
            {
                if(canreach(neib,target,adj,visited))
                return true;
            }

        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>>adj(edges.size()+1);
       
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            vector<bool>visited(edges.size()+1,false);
            if(canreach(u,v,adj,visited))
            return edge;
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        return {};
        
    }
};
