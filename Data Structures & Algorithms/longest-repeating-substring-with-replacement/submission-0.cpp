class Solution {
public:
    int characterReplacement(string s, int k) {
        //eeeeeeeee this i remember you had told me to take maps for such cases
        //so maps and replacements and we should return the total replacement number
        //we can use maps or vector since only 26 chars vector is slightly faster
        vector<int> freq(26);
        int l=0,r=0,mfreq=0,ans=0;
        
        while(l<=r && r<s.size())
        {
            freq[s[r]-'A']++;
        mfreq=max(mfreq,freq[s[r]-'A']);
            while(((r-l+1)-mfreq)>k)
            {
                freq[s[l]-'A']--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;

        }       
        return ans;
    }
};
