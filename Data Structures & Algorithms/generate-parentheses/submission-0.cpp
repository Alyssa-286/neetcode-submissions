class Solution {
public:
    void backtrack(int n,int open,int close,string &current,vector<string>&ans)
    {
        if(open==n && close==n)
        {
            ans.push_back(current);
            return;
        }
        if(open<n)
        {
            current.push_back('(');
            backtrack(n,open+1,close,current,ans);
            current.pop_back();
        }
        
        if(close<open)
        {
            current.push_back(')');
            backtrack(n,open,close+1,current,ans);
            current.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        string current="";
        vector<string>ans;
        int open=0,close=0;
        backtrack(n,open,close,current,ans);
        return ans;
    }
};
