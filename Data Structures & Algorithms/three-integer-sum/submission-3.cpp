class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //similar like 2 pointer but see array not sorted and we have to return 3 indices 
        // soo hmm also it says no duplicate triplets so hashmaps? or wwith 2 pointers only we can solve this?
    //aiyoooo maybe the third pointer can be mid ? is it like binary search?
    //understood no need for mid becuase not all cases work instead a fixed which moves like an iterator
    
    int l,r,fix,sum=0;
    sort(nums.begin(),nums.end());
    
    //suppose idx 0 
    fix=0;
    //do we need a vector yes or no hmm ;
    vector<vector<int>>a;
    for(fix=0;fix<nums.size();fix++)
    {
        if (fix > 0 && nums[fix] == nums[fix - 1]) {
                continue; 
            }
        l=fix+1;
        r=nums.size()-1;
    
        while(l<r)
        {
            sum=nums[fix]+nums[l]+nums[r];
            if(sum==0)
            {
                a.push_back({nums[fix], nums[l], nums[r]});
                while(l<r&&nums[l]==nums[l+1])
                l++;
                
                while(l<r&&nums[r]==nums[r-1])
                r--;
                r--;
                l++;
           
            }
            else if(sum>0)
            r--;
            else if(sum<0)
            l++;

        }
    }
        return a;
    }
};
