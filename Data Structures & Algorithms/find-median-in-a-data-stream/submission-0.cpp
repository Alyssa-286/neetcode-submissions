class MedianFinder {
    private:
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!minheap.empty()&&num<minheap.top())
        {
            maxheap.push(num);
        }
        else
        minheap.push(num);
        if(minheap.size()>maxheap.size()+1)
        {
            int top=minheap.top();
            minheap.pop();
            maxheap.push(top);
        }
        if(maxheap.size()>minheap.size()+1)
        {
            int top=maxheap.top();
            maxheap.pop();
            minheap.push(top);
        }
    }
    
    double findMedian() {
        if(minheap.size()>maxheap.size())
        return minheap.top();
        if(maxheap.size()>minheap.size())
        return maxheap.top();
        return (maxheap.top()+minheap.top())/2.0;
        
    }
};
