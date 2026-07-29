class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>count(26,0);
        for(auto t : tasks)
        {
            count[t-'A']++;
        }
        priority_queue<int>maxheap;
        for(auto x:count)
        {
            if(x>0)
            maxheap.push(x);
        }
        int time=0;
        queue<pair<int,int>>cdq;
        while(!maxheap.empty() || !cdq.empty())
        {
            time++;
            if(!maxheap.empty())
            {
                int remcount=maxheap.top()-1;
                maxheap.pop();
            
                if(remcount>0)
                {
                    int wakeuptime=time+n;
                    cdq.push({remcount,wakeuptime});
                }
            }
            if(!cdq.empty() && cdq.front().second==time)
            {
                maxheap.push(cdq.front().first);
                cdq.pop();
            }
        }
        return time;

    }
};
