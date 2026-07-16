class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l,r;
       /*  vector<int>v;
      for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                v.push_back(matrix[i][j]);
            }
        } */
        // now we optimize it
        int rows,cols;
        rows=matrix.size();
        cols=matrix[0].size();
        l=0;
        r=rows*cols-1;
        while(l<=r)
        {
           
            int mid=l+(r-l)/2;
             int value=matrix[mid/cols][mid%cols];
            if(value==target)
            return true;
            else if(value<target)
            l=mid+1;
            else
            r=mid-1;
        }
        return false;
    }
};
