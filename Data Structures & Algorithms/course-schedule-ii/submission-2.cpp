class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        vector<int>ans;
        for(auto x: prerequisites)
        {
            int a=x[0];
            int b=x[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int>q;
        int count =0;
        for(int i=0; i<numCourses;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            ans.push_back(cur);
            count++;
            for(auto neib : adj[cur])
            {
                indegree[neib]--;
                if(indegree[neib]==0)
                q.push(neib);
            }
        }
        if(count==numCourses)
        return ans;
        return {};
        
    }
};
