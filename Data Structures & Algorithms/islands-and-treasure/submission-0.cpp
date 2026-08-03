class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        queue<pair<int,int>>q;
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                if(grid[r][c]==0)
                q.push({r,c});
            }
        }
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();
            int r = cur.first;
            int c= cur.second;
            for(int k=0;k<4;k++)
            {
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0 && nr<rows && nc>=0 && nc<cols && grid[nr][nc]==INT_MAX)
                {
                    grid[nr][nc]=grid[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        
    }
};
