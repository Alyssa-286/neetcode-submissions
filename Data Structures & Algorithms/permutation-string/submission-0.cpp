class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //given 2 strings we have to check permutation i.e different ways the letters can be arranged
        //we can use the hash table maps to check this permutation?
        // like see s1 is abc sort it and it is abc and in s2 if you sort it it is abcel because no duplicates
        //so abc abc exists and we can check this through a sliding window and if they match true else false?
        //understood it takes too much time to compare every window if it is of size 1000
        //vector is better
        vector<int>s1f(26);
         vector<int>s2f(26);
        int l=0,r=0;
        for(char c:s1)
        {
            s1f[c-'a']++;
        }
        while(r<s2.size())
        {
            s2f[s2[r]-'a']++;
            if(r-l+1>s1.length())
            {
                s2f[s2[l]-'a']--;
                l++;
            }
            if(s1f==s2f)
            {
                return true;
            }
            r++;
        }
        return false;
    }
};
