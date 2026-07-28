class KthLargest {
    private:
    int kth;
    priority_queue<int,vector<int>,greater<int>>minheap;
public:
    KthLargest(int k, vector<int>& nums) {
        kth=k;
        for(auto x:nums)
        {
            
           // if(minheap.size()!=k)
            minheap.push(x);
            if(minheap.size()>kth)
            minheap.pop();
        }
        
    }
    
    int add(int val) {
       // if(minheap.size()<k)
        minheap.push(val);
        if(minheap.size()>kth)
        minheap.pop();
        return minheap.top();
        
    }
};
