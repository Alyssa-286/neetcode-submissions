class Solution {
public:
    void backtrack(int index,string digits,unordered_map<char,string>&mp,string current,vector<string>&ans)
    {
        if(index==digits.size())
        {
            ans.push_back(current);
            return;
        }
        for(char ch:mp[digits[index]])
        {
            current.push_back(ch);
            backtrack(index+1,digits,mp,current,ans);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
        return {};
        int index=0;
        unordered_map<char,string>mp=
        {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };

        string current;
        vector<string>ans;
        backtrack(index,digits,mp,current,ans);
        return ans;
        
    }
};
