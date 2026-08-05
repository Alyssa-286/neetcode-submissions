class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto x : prerequisites)
        {
            int a=x[0];
            int b=x[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int>q;
        int count=0;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        while(!q.empty())
            {
                int cur=q.front();
                q.pop();
                count++;
                for(auto neib : adj[cur])
                {
                    indegree[neib]--;
                    if(indegree[neib]==0)
                    q.push(neib);
                }
            }
        if(count==numCourses)
        return true;
        return false;
        }
 /*   bool dfs(int node, vector<vector<int>>&adj,vector<int>&state)
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
    */
    //this was std dfs now we will doo a bfs topological sort khan's algo

};
