class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //hmm no moodifying nums or no extra hashmaps for freq
         //direct brute
        int freq=0;
        int elem=0;
        bool seen=false;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
           { 
            if(nums[i]==nums[j])
            {
                seen=true;
                elem=nums[i];
            }
           }

        }
        if(seen== true)
        return elem;
        return -1;
        
    }
};
