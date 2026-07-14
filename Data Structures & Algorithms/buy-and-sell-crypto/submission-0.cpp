class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ch,profit=0,i,ans=0;//current price,cheapest;
        ch=prices[0];
        for(i=0;i<prices.size();i++)
        {
            ch=min(ch,prices[i]);
            profit=prices[i]-ch;
            ans=max(profit,ans);
        }
        return ans;

        
    }
};
