class Solution {
public:
int dp[1001][1001];
int rec(string &t1,string &t2,int i,int j){
   if(i==t1.size()||j==t2.size()){
    return 0;
   }
   if(dp[i][j]!=-1){
    return dp[i][j];
   }

   int take=0;int ntake=0;
    if(t1[i]==t2[j]){
         take=1+rec(t1,t2,i+1,j+1);
    }
    else{
      ntake=max(rec(t1,t2,i+1,j),rec(t1,t2,i,j+1));
    }
    return dp[i][j]=max(take,ntake);
}
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return rec(text1,text2,0,0);
    }
};