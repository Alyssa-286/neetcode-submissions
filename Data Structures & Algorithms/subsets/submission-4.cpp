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
        backtrack(index+1,nums,subsets,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        int index=0;
        vector<int>subsets;
        vector<vector<int>>ans;
        backtrack(index,nums,subsets,ans);
        return ans;
        
    }
};
/*
class Solution {
public:
    vector<vector<int>> answer;
    void backtrack(int start, vector<int>& nums, vector<int>& path){
        answer.push_back(path);

        // for all the choices
        for (int i = start; i < nums.size(); i++){
            // Choose 
            path.push_back(nums[i]);
            // Recurse
            backtrack(i + 1, nums, path);

            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> initPath;
        backtrack(0, nums, initPath);
        return answer;
    }
};

*/