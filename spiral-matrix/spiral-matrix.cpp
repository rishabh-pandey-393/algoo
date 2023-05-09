class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int>ans;
        vector<vector<bool>>check(m,vector<bool>(n,false));
        vector<int>a={0,1,0,-1};
        vector<int>b={1,0,-1,0};
        int x=0,y=0,k=0;
        for(int i=0;i<m*n;i++){
            ans.push_back(matrix[x][y]);
            check[x][y]=true;
            int nx=x+a[k];
            int ny=y+b[k];
            if(nx<m && nx>-1 && ny<n && ny>-1 && !check[nx][ny]){
                x=nx;y=ny;
            }
            else {
                k=(k+1)%4;
                x=x+a[k];
                y=y+b[k];
            }
        }
        return ans;
    }
};