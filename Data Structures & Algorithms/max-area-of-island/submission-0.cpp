class Solution {
public:
    int dfs(int r,int c,int rows,int cols,vector<vector<int>>&grid)
    {
        if(r<0||r>=rows||c<0||c>=cols||grid[r][c]==0)
        return 0;
        grid[r][c]=0;
        int curarea=1;
        curarea+=dfs(r-1,c,rows,cols,grid);
        curarea+=dfs(r+1,c,rows,cols,grid);
        curarea+=dfs(r,c-1,rows,cols,grid);
        curarea+=dfs(r,c+1,rows,cols,grid);
        return curarea;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int maxarea=0;
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                int currarea=dfs(r,c,rows,cols,grid);
                maxarea=max(currarea,maxarea);
            }
        }
        return maxarea;
    }
};
