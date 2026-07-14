class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int i,ans=0,water=0;
        vector<int> lmax(n),rmax(n);
        lmax[0]=height[0];
        rmax[n-1]=height[n-1];
        for(i=1;i<n;i++)
        {
            lmax[i]=max(lmax[i-1],height[i]);
        }
        for(i=n-2;i>=0;i--)
        {
            rmax[i]=max(rmax[i+1],height[i]);
        }
        for(i=0;i<n;i++)
        {
            water=min(lmax[i],rmax[i])-height[i];
            ans+=water;

        }


        return ans;
    }
};
