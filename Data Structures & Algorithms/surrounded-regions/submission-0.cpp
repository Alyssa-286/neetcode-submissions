class Solution {
public:
    void dfs(int r,int c,int rows, int cols,vector<vector<char>>& board)
    {
        if(r<0 || r>=rows || c<0 || c>= cols)
        return;
        if(board[r][c]!='O')
        return;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        board[r][c]='T';
        for(int k=0;k<4;k++)
        {
            int nr= r+dr[k];
            int nc=c+dc[k];
            dfs(nr,nc,rows,cols,board);
        }

    }
    void solve(vector<vector<char>>& board) {
        int rows=board.size();
        int cols=board[0].size();
        for(int r=0;r<rows;r++)
        {
            if(board[r][0]=='O')
            dfs(r,0,rows,cols,board);
            if(board[r][cols-1]=='O')
                dfs(r,cols-1,rows,cols,board);
           

        }
        for(int c=0;c<cols;c++)
        {
            if(board[0][c]=='O')
            dfs(0,c,rows,cols,board);
            if(board[rows-1][c]=='O')
            dfs(rows-1,c,rows,cols,board);
        }
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                if(board[r][c]=='O')
                board[r][c]='X';
                if(board[r][c]=='T')
                board[r][c]='O';
            }
        }
        
    }
};
