class Solution {
public:
int dp[1001][1001];
int rec(string &s,string &r,int i,int j){
    if(i==s.size()){
        return 0;
    }
    if(j==r.size()){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
   int take=0;
   int ntake=0;
    if(s[i]==r[j]){
        take=1+rec(s,r,i+1,j+1);
    }
    else{
        ntake=max(rec(s,r,i+1,j),rec(s,r,i,j+1));
    }
    return dp[i][j]=max(take,ntake);
}
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        string r=s;
        reverse(r.begin(),r.end());
       return rec(s,r,0,0);
    }
};