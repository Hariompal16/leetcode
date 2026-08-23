class Solution {
public:

int rec(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp){
    int n=grid.size()-1;
    int m=grid[0].size()-1;
  if(dp[i][j]!=-1){
    return dp[i][j];
  }
    if(i==n&&j==m){
        return grid[i][j];
    }

    else if(j==m){
        return dp[i][j]=grid[i][j]+rec(grid,i+1,j,dp);
    }
    else if(i==n){
        return dp[i][j]=grid[i][j]+rec(grid,i,j+1,dp);
    }
    else{
        return dp[i][j]=grid[i][j]+min(rec(grid,i+1,j,dp),rec(grid,i,j+1,dp));
    }
    return -1;
}
    int minPathSum(vector<vector<int>>& grid) {
vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return rec(grid,0,0,dp);
    }
};