class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),ans=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        pq.push({grid[0][0],0,0});
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int val=p[0],x=p[1],y=p[2];
            grid[x][y]=-1;
            ans=max(ans,val);
            if(x==m-1 && y==n-1) return ans;
            if(x+1<m && grid[x+1][y]!=-1) pq.push({grid[x+1][y],x+1,y});
            if(x-1>=0 && grid[x-1][y]!=-1) pq.push({grid[x-1][y],x-1,y});
            if(y+1<n && grid[x][y+1]!=-1) pq.push({grid[x][y+1],x,y+1});
            if(y-1>=0 && grid[x][y-1]!=-1) pq.push({grid[x][y-1],x,y-1});
        }
        return 0;
    }
};