class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        map<int,int>mp;
        for(int i=0;i<k;i++) mp[i]=0;
        int n=arrival.size();
        vector<int>v(k);
        int t=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        for(int i=0;i<n;i++){
            while(pq.size() && pq.top().first<=arrival[i]){
                mp[pq.top().second]=1;
                pq.pop();
            }
            if(mp.size()==0) continue;
            int ser;
            auto it=mp.lower_bound(i%k);
            if(it!=mp.end()){
                ser=it->first;
                cout<<ser<<" ";
                mp.erase(ser);
            }
            else{
                it=mp.begin();
                ser=it->first;
                cout<<ser<<" ";
                mp.erase(ser);
            }
            v[ser]++;
            pq.push({arrival[i]+load[i],ser});
        }
        int mx=-1;
        vector<int>ans;
        for(int i=0;i<k;i++){
            if(mx<v[i]){
                while(ans.size()) ans.pop_back();
                mx=v[i];
                ans.push_back(i);
            }
            else if(mx==v[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};