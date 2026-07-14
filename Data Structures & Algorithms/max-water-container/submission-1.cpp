class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l,r,area=0,ans=0;
        l=0;
        r=heights.size()-1;
        while(l<r)
        {
            area=min(heights[l],heights[r])*(r-l);
            ans=max(area,ans);
            if(heights[l]<heights[r])
            {
                l++;
            }
            else
            r--;

        }

        return ans;
    }
};
