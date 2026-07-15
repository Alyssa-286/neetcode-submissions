class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        if(s.empty())
        return true;
        else
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            st.push(s[i]);
            else if(s[i]==')'||s[i]=='}'||s[i]==']')
            {
                if(st.empty())
                return false;
                else if((st.top()=='('&&s[i]==')')||(st.top()=='{'&&s[i]=='}')||(st.top()=='['&&s[i]==']'))
                st.pop();
                else
                return false;
            }
        }
        if(st.empty())
        return true;
        return false;
        
    }
};
