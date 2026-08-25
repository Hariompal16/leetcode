class Solution {
public:
int r;
int c;
  int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};
bool valid(int i,int j){
    return i>=0&&i<r&&j>=0&&j<c;
}
    int numIslands(vector<vector<char>>& grid) {
        r=grid.size();
        c=grid[0].size();
        queue<pair<int,int>>q;
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    q.push({i,j});
                    grid[i][j]='0';
                    count++;
                    while(!q.empty()){
                    
                    
                        int new_i=q.front().first;
                        int new_j=q.front().second;
                        q.pop();
                         for(int k=0;k<4;k++){
                            if(valid(new_i+row[k],new_j+col[k])&&grid[new_i+row[k]][new_j+col[k]]=='1'){
                                q.push({new_i+row[k],new_j+col[k]});
                                grid[new_i+row[k]][new_j+col[k]]='0';
                            }
                         }
                    
                }
                }
                
            }
        }
        return count;
    }
};