class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //okayyy we need the longest substring ie we need the continous form or part of the string and we need to return the length of the substring
        //sooo since no duplicates hashing or hasmaps?
        //hmmm since it is under sliding window how do we do that here make the length ooooo maybe we can returnn the length of the window??
        int l=0,r=0,ans=0;
        unordered_set<char>w;
        while(l<=r&&r<s.size())
        {
           
            while(w.count (s[r]))
            {
                w.erase(s[l]);
                l++;
            }
           // if(!w.count(r))
            w.insert(s[r]);
            ans=max(ans,(int)w.size());
            r++;
        }
        return ans;
        
    }
};
