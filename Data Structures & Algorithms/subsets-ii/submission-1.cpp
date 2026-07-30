class Solution {
public:
    void backtrack(int index,vector<int>& nums,vector<int> &subsets,vector<vector<int>> &ans)
    {
        if(index==nums.size())
        {
            ans.push_back(subsets);
            return;
        }
        subsets.push_back(nums[index]);
        backtrack(index+1,nums,subsets,ans);
        subsets.pop_back();
        while(index+1<nums.size() && nums[index]==nums[index+1])
        {
            index++;
        }
        backtrack(index+1,nums,subsets,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int index=0;
        vector<int>subsets;
        vector<vector<int>>ans;
        backtrack(index,nums,subsets,ans);
        return ans;
        
    }
};
