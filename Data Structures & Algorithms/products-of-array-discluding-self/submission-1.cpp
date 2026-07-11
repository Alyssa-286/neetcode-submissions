class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int i;
        int n=a.size();
        vector <int> p(n),s(n),arr(n);
       
        p[0]=1;
        s[n-1]=1;
        for(i=1;i<n;i++)
        {
            p[i]=p[i-1]*a[i-1];
        }
        for(i=n-2;i>=0;i--)
        {
            s[i]=s[i+1]*a[i+1];
        }
        for(i=0;i<n;i++)
        {
            arr[i]=p[i]*s[i];
        }

        return arr;

    }
};
