class Solution {
public:
    int compute(int op1,char op,int op2)
    {
        switch(op)
                {
                    case '+': return op1+op2;
                    case '-': return op1-op2;
                    case '*': return op1*op2;
                    case '/': return op1/op2;
                    default: return 0;
                }
    }
    int evalRPN(vector<string>& s) {
        stack<int>st;
        int i=0;
        for(i=0;i<s.size();i++)
        {

           if(s[i]=="+"||s[i]=="-"||s[i]=="/"||s[i]=="*")
            {
                int op2=st.top();
                st.pop();
                int op1=st.top();
                st.pop();
                char op=s[i][0];
                int res=compute(op1,op,op2);
                st.push(res);
            }
            else
            {
                st.push(stoi(s[i]));
            }
           
        }
        return st.top();
        
    }
     
};
