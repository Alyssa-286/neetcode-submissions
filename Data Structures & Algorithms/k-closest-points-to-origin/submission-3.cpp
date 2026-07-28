class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>>maxheap;//why cant i use priority_queue<pair<int,pair<int,int>>>maxheap 
        //you can use it but again you will have to convert it back to vector because the function expects you to return that back sooo
        for(auto p:points)
        {
            int x=p[0];
            int y=p[1];
            int dist=x*x+y*y;
            maxheap.push({dist,p});
            if(maxheap.size()>k)
            maxheap.pop();
        }
        vector<vector<int>>result;
        while(!maxheap.empty())
        {
            result.push_back(maxheap.top().second);
            maxheap.pop();
        }
        return result;
    }
};
