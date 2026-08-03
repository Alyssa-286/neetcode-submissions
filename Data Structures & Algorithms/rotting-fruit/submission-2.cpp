class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    /*    int rows=grid.size();
        int cols=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                if(grid[r][c]==2)
                q.push({r,c});
                else if(grid[r][c]==1)
                fresh++;
            }
        }
        if(fresh==0)
        return 0;
        int mins=0;
        while(!q.empty() && fresh>0)
        {
            int size=q.size();
            mins++;
            for(int i=0;i<size;i++)
            {
                auto cur=q.front();
                q.pop();
                int r=cur.first;
                int c=cur.second;
                int upr=r-1;
                int upc=c;
                if(upr>=0 && grid[upr][upc]==1)
                {
                    grid[upr][upc]=2;
                    fresh--;
                    q.push({upr,upc});
                }
                
                int dr=r+1;
                int dc=c;
                if(dr<rows && grid[dr][dc]==1)
                {
                    grid[dr][dc]=2;
                    fresh--;
                    q.push({dr,dc});
                }
               
                int lr=r;
                int lc=c-1;
                if(lc>=0 && grid[lr][lc]==1)
                {
                    grid[lr][lc]=2;
                    fresh--;
                    q.push({lr,lc});
                }
                
                int rr=r;
                int rc=c+1;
                if(rc<cols && grid[rr][rc]==1)
                {
                    grid[rr][rc]=2;
                    fresh--;
                    q.push({rr,rc});
                }
            }
        }
         if(fresh==0)
                return mins;
                return -1;*/
       int rows=grid.size();
        int cols=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                if(grid[r][c]==2)
                q.push({r,c});
                else if(grid[r][c]==1)
                fresh++;
            }
        }
        if(fresh==0)
        return 0;
        int mins=0;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty() && fresh>0)
        {
            int size=q.size();
            mins++;
            for(int i=0;i<size;i++)
            {
                auto cur=q.front();
                q.pop();
                int r=cur.first;
                int c=cur.second;
                for(int k=0;k<4;k++)
                {
                    int nr=r+dr[k];
                    int nc=c+dc[k];
                    if(nr>=0 && nr<rows && nc>=0 && nc<cols && grid[nr][nc]==1)
                    {
                        grid[nr][nc]=2;
                        fresh--;
                        q.push({nr,nc});

                    }
                }
            }
        }
         if(fresh==0)
                return mins;
                return -1;

    }
};
