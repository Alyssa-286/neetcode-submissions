class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //okay we are given an arr and always only one valid soln  and o(1) additional space means we can have a pair maybe?
        //what we can do is idx1 and idx2 not same and idx1<idx2
        //soo hashmaps?
        //i dont know lets try this
        //wrong we dont need extra memory and we need to return the indecies and it is stored in a vector not pair 
        // imp sorted array think if you can impelement the twp pointer always 
        int l,r;
        l=0;
        r=nums.size()-1;
        
        vector<int> a;
        while(l<r)
        {
            int sum=0;
            sum=nums[l]+nums[r];
            if(sum==target)
            {
                a.push_back(l+1);
                a.push_back(r+1);
                return a;
            }
            else if(sum>target)
            {
                r--;
            }
            else
            {
                l++;
            }
            

        }
        return a;
    }
};
