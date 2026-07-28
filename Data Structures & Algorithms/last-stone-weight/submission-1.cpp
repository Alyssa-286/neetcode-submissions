class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxpq;
        for(auto x:stones)
        {
            maxpq.push(x);
        }
        while(maxpq.size()>1)
        {
            int l=maxpq.top();maxpq.pop();
            int sl=maxpq.top();maxpq.pop();
           // if(l==sl)
            //continue;
            //if(l<sl)
            //l=l-sl;
            if(l!=sl)
            maxpq.push(l-sl);
        }
        if(!maxpq.empty())
        return maxpq.top();
        return 0;
        
    }
};
