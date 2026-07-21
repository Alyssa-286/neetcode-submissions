class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     /*   //hmm no moodifying nums or no extra hashmaps for freq
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
        */
        int slow=nums[0];
        int fast=nums[0];
        do
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        slow=nums[0];
        //dont do a do while here because after first do while whatt if it has slow == fast already so check then do
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
       // if(slow==fast) no need of this condition tooo becausse if it is out of while loop it automatically means that slow==fast
        return slow;
      //  return -1; not required because they have confirmed that it has one duplicate exactly
        
    }
};
