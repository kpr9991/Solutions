iDea:-->Four corners of grid lo zeroes unte vaatiki connect ayina anni nodes ni mark chesey.
2.Next time, O's anni X's chesey.
3.Now already mark chesina 'N''s ni O's chesey.Thats it.
class Solution {
public:
    void dfs(vector<vector<char> > &board,int i,int j,int rows,int cols){
        if(i<0 || j<0 || i>=rows || j>=cols)
            return ;
        if(board[i][j]!='O')
            return ;
        board[i][j]='N';
        dfs(board,i+1,j,rows,cols);
        dfs(board,i-1,j,rows,cols);
        dfs(board,i,j+1,rows,cols);
        dfs(board,i,j-1,rows,cols);
    }
    void solve(vector<vector<char>>& board) {
        
        int rows=board.size();
        if(rows==0)
            return;
        int cols=board[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i==0 || i==rows-1 || j==0 || j==cols-1)
                {
                    if(board[i][j]=='O'){
                        dfs(board,i,j,rows,cols);
                    }
                }
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='O')
                board[i][j]='X';
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='N')
                board[i][j]='O';
            }
        }
        
        return;
        
    }
};
