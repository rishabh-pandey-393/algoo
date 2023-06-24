class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        unordered_map<int,int>mp,ind;
        vector<pair<int,int>>v;
        for(int i=0;i<logs.size();i++) v.push_back({logs[i][1],logs[i][0]});
        sort(v.begin(),v.end());
        for(int i=0;i<queries.size();i++) ind[queries[i]]=i;
        sort(queries.begin(),queries.end());
        int st=0,en=0;
        vector<int>ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int start=max(0,queries[i]-x);
            int end=queries[i];
            while(en<v.size() && v[en].first<=end){
                mp[v[en].second]++;
                en++;
            } 
            while(st<v.size() && v[st].first<start){
                mp[v[st].second]--;
                if(mp[v[st].second]==0) mp.erase(v[st].second);
                st++;
            }
            ans[ind[queries[i]]]=n-mp.size();
        }
        return ans;
    }
};