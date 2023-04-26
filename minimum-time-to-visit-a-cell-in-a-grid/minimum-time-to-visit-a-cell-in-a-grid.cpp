class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        if(grid[0][1]>1 && grid[1][0]>1) return -1;
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        vector<vector<int>>vis(r,vector<int>(c,0));
        vector<int>d={1,0,-1,0,1};
        pq.push({0,0,0});
        while(!pq.empty()){
            int t=pq.top()[0];
            int x=pq.top()[1];
            int y=pq.top()[2];
            pq.pop();
            if(x==r-1 && y==c-1) return t;
            if(vis[x][y]) continue;
            vis[x][y]=1;
            for(int i=0;i<4;i++){
                int xx=x+d[i];
                int yy=y+d[i+1];
                if(xx<0 or yy<0 or xx>=r or yy>=c or vis[xx][yy]) continue;
                int diff=(grid[xx][yy]-t)%2==0;
                if(t>=grid[xx][yy]) pq.push({t+1,xx,yy});
                else pq.push({grid[xx][yy]+diff,xx,yy});
            }
        }
        return -1; 
    }
};