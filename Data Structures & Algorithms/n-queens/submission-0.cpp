class Solution {
public:
    bool issafe(int row,int col,vector<string>&board)
    {
        //only 3 checks see one we care about queens above us so same col upper right then upper left
        for(int r=0;r<row;r++)
        {
            if(board[r][col]=='Q')
            return false;
        }
        int r=row-1;
        int c=col-1;
        while(r>=0 && c>=0)
        {
            if(board[r][c]=='Q')
            return false;
            r--;
            c--;
        }
         r=row-1;
         c=col+1;
        while(r>=0 && c<board.size())//n
        {
            if(board[r][c]=='Q')
            return false;
            r--;
            c++;
        }
        return true;

    }
    void backtrack(int row,vector<string>&board,int n,vector<vector<string>>&ans)
    {
        if(row==n)
        {
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++)
        {
            if(!issafe(row,col,board))
            continue;
            board[row][col]='Q';
            backtrack(row+1,board,n,ans);
            board[row][col]='.';
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        int row=board.size();
        int col=board[0].size();
        vector<vector<string>>ans;

        backtrack(0,board,n,ans);
        return ans;
    }
};
