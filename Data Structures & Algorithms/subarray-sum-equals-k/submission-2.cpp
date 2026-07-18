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
        int i,j,count=0,n;
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
        return count;
    }
};