class Solution {
public:
    vector<int> topKFrequent(vector<int>&a, int k) 
    {
        //normal count var method with traversal is slow maybe use hasmaps?
        unordered_map <int, int> mp;
        vector <vector<int>> bucket(a.size()+1);
        vector<int>ans;
        for(int i : a)
            mp[i]++;
        for(auto p:mp)
            bucket[p.second].push_back(p.first);
        for (int i = bucket.size() - 1; i >= 0; i--)
        {
            for (int num : bucket[i])
            {
                ans.push_back(num);

                if (ans.size() == k)
                    return ans;
            }
        }
        return ans;
    }
};
