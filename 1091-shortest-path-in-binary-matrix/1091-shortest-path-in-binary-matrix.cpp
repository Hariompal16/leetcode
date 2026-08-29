class Solution {
public:
int r;

int c;
int row[8]={-1,0,0,1,-1,-1,1,1};
int col[8]={0,-1,1,0,1,-1,-1,1};
bool valid(int i,int j){
   return i>=0&&i<=r&&j>=0&&j<=c;
}
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        r=grid.size()-1;
        c=grid[0].size()-1;
        queue<pair<int,int>>q;
        if(grid[0][0]==0)
        q.push({0,0});
     int count=0;
        while(!q.empty()){
            count++;
           
            int size=q.size();
            for(int i=0;i<size;i++){
            int new_x=q.front().first;
            int new_y=q.front().second;
            q.pop();
            if(new_x==grid.size()-1&&new_y==grid[0].size()-1){
                return count;
            }
            for(int k=0;k<8;k++){
                if(valid(new_x+row[k],new_y+col[k])&&grid[new_x+row[k]][new_y+col[k]]==0){
                    grid[new_x+row[k]][new_y+col[k]]=1;
                    q.push({new_x+row[k],new_y+col[k]});
                }
            }
            }
        }
        return -1;
    }
};