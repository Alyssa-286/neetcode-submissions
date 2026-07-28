class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //jk brute force
       // sort(nums.begin(),nums.end());
     //return nums[nums.size()-k]; craazzyyy how 2 linessss can solve this heheehhehe
    //okay okayy minheap hehe
    priority_queue<int,vector<int>,greater<int>>minheap;
    for(auto p:nums)
    {
        minheap.push(p);
        if(minheap.size()>k)
        minheap.pop();
    }
    return minheap.top();
    }
};
