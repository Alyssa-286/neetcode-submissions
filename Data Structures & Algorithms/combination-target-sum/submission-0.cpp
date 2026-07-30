class Solution {
public:
    void backtrack(int sum,int target,int index,vector<int>&nums,vector<int>&current,vector<vector<int>>&ans)
    {
        if(sum==target)
        {
            ans.push_back(current);
            return;
        }
        if(sum>target)
        {
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            current.push_back(nums[i]);
            sum+=nums[i];
            backtrack(sum,target,i,nums,current,ans);
            sum-=nums[i];
            current.pop_back();
        
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int index=0; int sum=0;
        vector<int>current;
        vector<vector<int>>ans;
        backtrack(sum,target,index,nums,current,ans);
        return ans;
    }
};
