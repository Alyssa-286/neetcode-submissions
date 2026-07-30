class Solution {
public:
    void backtrack(vector<int>&current,vector<int>&nums,vector<bool>&visited,vector<vector<int>>&ans)
    {
        if(current.size()==nums.size())
        {
            ans.push_back(current);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(visited[i])
            continue;
            else
            {
                visited[i]=true;
                current.push_back(nums[i]);
            }
            backtrack(current,nums,visited,ans);
            current.pop_back();
            visited[i]=false;

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>visited(nums.size(),false);
        vector<int>current;
        vector<vector<int>>ans;
      //  int index=0;
        backtrack(current,nums,visited,ans);
        return ans;

    }
};
