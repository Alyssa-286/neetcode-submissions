class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //now use a map and check if they are continuous and keep increasing the count and then return the lenght or the count??
        //okayy understood sort takes nlogn time so no sort without that we can chexk with sets if n-1 exists niceeeeeee start a sequence
        unordered_set<int>s(nums.begin(),nums.end());
        int longest=0;
        //x is iterative
        //cl is current length;
        //soc is start or current ie start of the sequence
        for(auto x:s)
        {
            int cl=0;int soc=x;
            if (!s.count(x-1))
            {
                soc=x;
                cl=1;
           
            while(s.count(soc+1))
        
            { 
                cl++;
                soc++;
            }
            }
             longest=max(longest,cl);
            

        }
       
        return longest;


    }
};
