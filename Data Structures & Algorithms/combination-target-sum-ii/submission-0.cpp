class Solution {
public:
        void backtrack(int sum,int target,int index,vector<int>&candidates,vector<int>&current,vector<vector<int>>&ans)
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
        for(int i=index;i<candidates.size();i++)
        {
            if(i>index && candidates[i]==candidates[i-1])
            continue;
            current.push_back(candidates[i]);
            sum+=candidates[i];
            backtrack(sum,target,i+1,candidates,current,ans);
            sum-=candidates[i];
            current.pop_back();
        
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int index=0; int sum=0;
        vector<int>current;
        vector<vector<int>>ans;
        backtrack(sum,target,index,candidates,current,ans);
        return ans;
        
    }
};
