class Solution {
public:
    int r;
    int c;
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};

    bool valid(int i,int j){
        return i>=0 && i<r && j>=0 && j<c;
    }

    void solve(vector<vector<char>>& board) {

        queue<pair<int,int>> q;

        r=board.size();
        c=board[0].size();

        // Top boundary
        for(int i=0;i<c;i++){
            if(board[0][i]=='O'){
                board[0][i]='t';
                q.push(make_pair(0,i));
            }
        }

        // Left boundary
        for(int i=1;i<r;i++){
            if(board[i][0]=='O'){
                board[i][0]='t';
                q.push(make_pair(i,0));
            }
        }

        // Bottom boundary
        for(int i=1;i<c;i++){
            if(board[r-1][i]=='O'){
                board[r-1][i]='t';
                q.push(make_pair(r-1,i));
            }
        }

        // Right boundary
        for(int i=1;i<r-1;i++){
            if(board[i][c-1]=='O'){
                board[i][c-1]='t';
                q.push(make_pair(i,c-1));
            }
        }

        while(!q.empty()){

            int new_i=q.front().first;
            int new_j=q.front().second;
            q.pop();

            for(int k=0;k<4;k++){

                int ni=new_i+row[k];
                int nj=new_j+col[k];

                if(valid(ni,nj) && board[ni][nj]=='O'){
                    board[ni][nj]='t';
                    q.push(make_pair(ni,nj));
                }
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){

                if(board[i][j]=='t'){
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }

            }
        }
    }
};