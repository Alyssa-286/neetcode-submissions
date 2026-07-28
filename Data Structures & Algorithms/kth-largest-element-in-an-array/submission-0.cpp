class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //jk brute force
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
        
    }
};
