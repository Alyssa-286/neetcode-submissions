class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        unordered_set<int>s;
        for(auto x:nums)
    {
        if(s.count(x))
        return 1;
        s.insert(x);
    }
    return 0;
    }
};