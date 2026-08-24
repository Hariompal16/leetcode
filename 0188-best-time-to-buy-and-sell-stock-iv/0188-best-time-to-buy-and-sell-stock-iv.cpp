class Solution {
public:
int dp[1001][2][101];
int rec(int k,vector<int>& prices,int buy,int count,int i){
    if(i>=prices.size()){
        return 0;
    }
int profit=0;

if(count>=k){
    return 0;
}
if(dp[i][buy][count]!=-1){
    return dp[i][buy][count];
}

    if(count<k){
        if(buy){
          profit=max(-prices[i]+rec(k,prices,0,count,i+1),0+rec(k,prices,1,count,i+1));
        }
        else{
            profit=max(prices[i]+rec(k,prices,1,count+1,i+1),0+rec(k,prices,0,count,i+1));
        }
    }

    return dp[i][buy][count]=profit;
}
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return rec(k,prices,1,0,0);
    }
};