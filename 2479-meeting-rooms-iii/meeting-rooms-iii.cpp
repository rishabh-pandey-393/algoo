class Solution {
public:
    typedef long long ll;
    int mostBooked(int m, vector<vector<int>>& meetings) {
        priority_queue<ll,vector<ll>,greater<>>free;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>>used;
        for(int i=1;i<=m;i++) free.push(i);
        map<ll,ll>mp;
        int n=meetings.size();
        sort(meetings.begin(),meetings.end());
        for(int i=0;i<n;i++){
            ll av=meetings[i][0];
            while(used.size() && used.top().first<=av){
                free.push(used.top().second);
                used.pop();
            }
            if(free.size()){
                ll x=free.top();
                free.pop();
                used.push({meetings[i][1],x});
                mp[x]++;
            }
            else{
                pair<ll,ll>p=used.top();
                used.pop();
                used.push({p.first+meetings[i][1]-meetings[i][0],p.second});
                mp[p.second]++;
            }
        }
        
        int ans;
        int mx=INT_MIN;
        for(auto it:mp){
            if(it.second>mx){
                mx=it.second;
                ans=it.first;
            }
        }
        return ans-1;
    }
};