class Solution {
public:
    bool dfs(int node, vector<vector<int>>&adj,vector<int>&state)
    {
        if(state[node]==1)
        return true;
        if(state[node]==2)
        return false;
        state[node]=1;
        for(auto neib : adj[node])
        {
            if(dfs(neib,adj,state))
            return true;
        }
        state[node]=2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>state(numCourses,0);
        for(auto x : prerequisites)
        {
            int a=x[0];
            int b=x[1];
            adj[b].push_back(a);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(state[i]==0 && dfs(i,adj,state))
            return false;
        }
        return true;
    }
};
