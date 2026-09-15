class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int diff=0;
        int maxx=INT_MIN;
        for(int i=prices.size()-1;i>=0;i--){
            maxx=max(maxx,prices[i]);
            if(abs(prices[i]-maxx)>diff){
                diff=abs(prices[i]-maxx);
            }
        }
        return diff;
    }
};