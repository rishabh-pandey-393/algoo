bool comp(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}
class Solution {
public:
    int find(int x,vector<int>&par){
        if(par[x]==x) return x;
        return par[x]=find(par[x],par);
    }
    void join(int a,int b,vector<int>&par){
        a=find(a,par);
        b=find(b,par);
        if(a!=b) par[a]=b;
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<int>par(n);
        for(int i = 0; i<n; i++) par[i] = i;
        for(int i = 0; i<queries.size(); i++) queries[i].push_back(i);
        
        sort(queries.begin(),queries.end(),comp);
        sort(edges.begin(),edges.end(),comp);
        vector <bool> ans(queries.size(),false);
        int idx = 0;
        for(int i = 0; i<queries.size(); i++){
            while(idx<edges.size() and edges[idx][2]<queries[i][2]){
                join(edges[idx][0],edges[idx][1],par);
                idx++;
            }
            if(find(par[queries[i][0]],par) == find(par[queries[i][1]],par)) ans[queries[i][3]] = true;
        }
        return ans;
    }
};