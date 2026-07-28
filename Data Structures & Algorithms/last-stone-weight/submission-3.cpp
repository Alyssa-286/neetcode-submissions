class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      /*  priority_queue<int>maxpq;
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
        */
         priority_queue<int> q;
        for(int i=0; i<stones.size(); i++){
            q.push(stones[i]);
        }
        while(q.size()>1){
        
            int a= q.top();
            q.pop();
            int b= q.top();
            if(a==b){
                q.pop();
            }
            else{
                if(a>b){
                    q.pop();
                    q.push(a-b);
                }
                else{
                    continue;
                }
            }
        }
        
        if(!q.empty()){
            return q.top();
        }
        else{
            return 0;
        }
    }
};
