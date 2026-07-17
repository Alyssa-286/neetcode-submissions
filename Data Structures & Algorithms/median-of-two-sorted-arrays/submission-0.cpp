class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //first try brute force will come back later;
        vector<int>nums3;
        nums3.insert(nums3.end(),nums1.begin(),nums1.end());
        nums3.insert(nums3.end(),nums2.begin(),nums2.end());
        sort(nums3.begin(),nums3.end());
        float ans=0;
        int n=nums3.size();
        if((nums3.size())%2!=0)
        {
            ans=nums3[n/2];
            return ans;
        }
        else
        {
          ans= (nums3[n/2 -1] + nums3[n/2])/2.0;
          return ans;

        }
        
    }
};
