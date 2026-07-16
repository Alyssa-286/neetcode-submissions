class Solution {
public:
    int findMin(vector<int> &arr) {
        int mini=*min_element(arr.begin(),arr.end());
        return mini;
        
    }
};
