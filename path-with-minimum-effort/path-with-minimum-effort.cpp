class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>>d(m,vector<int>(n,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        d[0][0]=0;
        pq.push({0,0,0});
        while(pq.size()){
            vector<int>v=pq.top();
            pq.pop();
            int dis=v[0],x=v[1],y=v[2];
            if(dis>d[x][y]) continue;
            if(x==m-1 && y==n-1) return dis;
            vector<int>dd={1,0,-1,0,1};
            for(int i=0;i<4;i++){
                int xx=x+dd[i];
                int yy=y+dd[i+1];
                if(xx<0 or xx>=m or yy<0 or yy>=n) continue;
                if(max(abs(heights[xx][yy]-heights[x][y]),dis)<d[xx][yy]){
                    d[xx][yy]=max(abs(heights[xx][yy]-heights[x][y]),dis);
                    pq.push({d[xx][yy],xx,yy});
                }
            }
        }
        return -1;
    }
};