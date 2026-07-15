class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>>cars;
        int n=position.size();
        for(int i=0;i<n;i++)
        {
            double time= double(target-position[i])/speed[i];
            cars.push_back({position[i],time});
        }
        sort(cars.begin(),cars.end());
          double maxtime=0;
            int fleet=0;
            for(int i=n-1;i>=0;i--)
            {
                if(cars[i].second>maxtime)
                {
                    fleet++;
                    maxtime=cars[i].second;
                }
            }
            return fleet;
    }
};
