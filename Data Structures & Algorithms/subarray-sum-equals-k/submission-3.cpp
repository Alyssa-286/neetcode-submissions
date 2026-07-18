class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     /*   int i,maxi=nums[0];
        int cur=nums[0];
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            cur=max(cur,cur+nums[i]);
            maxi=max(cur,maxi);
            if(maxi==k)
            {
                count++;
            }

        }
        return count;
        */
        //wrong because we don't need the max at all 
      /*  int i,j,count=0,n;
        n=nums.size();
        for(i=0;i<n;i++)
        {   int sum=0;
            for(j=i;j<n;j++)
            {
                sum+=nums[j];
                if(sum==k)
                count++;
            }
        }
        return count;*/

        //done brute force
        //now optimize it

        unordered_map<int,int> mp;

        mp[0] = 1;

        int sum = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            if(mp.count(sum - k))
                count += mp[sum - k];

            mp[sum]++;
        }

        return count;
    }
};