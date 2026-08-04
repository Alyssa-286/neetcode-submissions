class Solution {
public:
    void dfs(int r,int c,int rows,int cols,int prevheight,vector<vector<bool>>&visited,vector<vector<int>>&heights)                             
    {
        if(r<0 || r>=rows || c<0 || c>=cols )
        return;
        if(visited[r][c])
        return;
        if(heights[r][c]<prevheight)
        return;
        visited[r][c]=true;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int k=0;k<4;k++)
        {
            int nr=r+dr[k];
            int nc=c+dc[k];
            prevheight=heights[r][c];
            dfs(nr,nc,rows,cols,prevheight,visited,heights);
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows=heights.size();
        int cols=heights[0].size();
        vector<vector<bool>>vispac(rows,vector<bool>(cols,false));
        vector<vector<bool>>visatlan(rows,vector<bool>(cols,false));
       
            for(int c=0;c<cols;c++)
            {
                dfs(0,c,rows,cols,heights[0][c],vispac,heights);
                dfs(rows-1,c,rows,cols,heights[rows-1][c],visatlan,heights);
            }
         for(int r=0;r<rows;r++)
        {
            dfs(r,0,rows,cols,heights[r][0],vispac,heights);
            dfs(r,cols-1,rows,cols,heights[r][cols-1],visatlan,heights);
        }
        vector<vector<int>>result;
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                if(vispac[r][c]&& visatlan[r][c])
                result.push_back({r,c});
            }
        }
        return result;


    }
};
