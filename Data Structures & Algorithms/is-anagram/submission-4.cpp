class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        if(s.size() != t.size())
    return false;
        for(auto x:s)
        {
            mp[x]++;
        }
        for(auto x:t)
        {
            mp[x]--;
            if(mp[x]<0)
            return 0;
        }
        return 1;
    }
};
