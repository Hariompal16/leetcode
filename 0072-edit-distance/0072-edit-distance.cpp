class Solution {
public:
int dp[501][501];
int rec(string s1,string s2,int i,int j){
    if(i==s1.size()){
        return s2.size()-j;
    }
    if(j==s2.size()){
        return s1.size()-i;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int insert=0;
    int replace=0;
    int delet=0;
    if(s1[i]==s2[j]){
        return dp[i][j]=rec(s1,s2,i+1,j+1);
    }
    else{
        //insert
       insert=1+rec(s1,s2,i,j+1);


       //delete 
       delet=1+rec(s1,s2,i+1,j);

       replace=1+rec(s1,s2,i+1,j+1);
    }
    int a=min(insert,delet);

    return dp[i][j]=min(a,replace);
}
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return rec(word1,word2,0,0);
    }
};