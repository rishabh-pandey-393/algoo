class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int>v;
        int m=wall.size();
        int ans=0;
        for(int i=0;i<m;i++){
            int x=0;
            for(int j=0;j<wall[i].size()-1;j++){
                x+=wall[i][j];
                v[x]++;
                ans=max(ans,v[x]);
            }
        }
        return m-ans;
    }
};