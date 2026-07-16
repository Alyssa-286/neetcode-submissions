class Solution {
public:
    int mySqrt(int n) {
         int l,r,ans=0;
        l=0;
        r=n;
        while(l<=r)
        {
            
            long long mid=l+(r-l)/2;
            long long sq=mid*mid;
            if(sq==n)
            return mid;
            else if(sq<n)
           { ans=mid;
            l=mid+1;}
            else  
            r=mid-1;
        }
        return ans;
        
    }
};