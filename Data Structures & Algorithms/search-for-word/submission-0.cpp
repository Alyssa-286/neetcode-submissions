class Solution {
public:
    bool backtrack(int r,int c,int index,vector<vector<char>>& board,string word,vector<vector<bool>>&visited)
    {
        if(index==word.size())
        {
            return true;
        }
        if(r<0||r>=board.size() || c<0|| c>=board[0].size())
        {
            return false;
        }
        if(visited[r][c])
        {
            return false;
        }
        if(board[r][c]!=word[index])
        {
            return false;
        }
        visited[r][c]=true;
       bool found= backtrack(r-1,c,index+1,board,word,visited)||
        backtrack(r+1,c,index+1,board,word,visited)||
        backtrack(r,c-1,index+1,board,word,visited)||
        backtrack(r,c+1,index+1,board,word,visited);
        visited[r][c]=false;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),false));
        int index=0;
        for(int r=0;r<board.size();r++)
        {
            for(int c=0;c<board[0].size();c++)
            {
                if(backtrack(r,c,index,board,word,visited))
                return true;
            }
        }
        return false;
    }
};
