class Solution {
public:
    bool isPalindrome(string s) {
        string rev;
        string clean = "";

        for(char ch : s)
        {
            if(isalnum(ch))
            {
                clean += tolower(ch);
            }
        }
        rev=clean;
        reverse(rev.begin(),rev.end());
        if(rev==clean)
        return true;
        return false;
    }
};
