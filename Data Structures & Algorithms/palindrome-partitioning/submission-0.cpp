class Solution {
public:
    bool ispal(string &s,int left,int right)
    {
        while(left<right)
        {
            if(s[left]!=s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void backtrack(int start,vector<string> &current,string &s,vector<vector<string>>&ans)
    {
        if(start==s.size())
        {
            ans.push_back(current);
            return;
        }
        for(int end=start;end<s.size();end++)
        {
            if(!ispal(s,start,end))
            continue;
            current.push_back(s.substr(start, end - start + 1));
            backtrack(end+1,current,s,ans);
            current.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> current;
        vector<vector<string>>ans;
        int start=0;
        int left=0;
        int right=s.size()-1;
        backtrack(start,current,s,ans);
        return ans;
        
    }
};
