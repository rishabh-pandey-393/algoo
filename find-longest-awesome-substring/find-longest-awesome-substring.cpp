class Solution {
public:
    int longestAwesome(string s) {
        int n=s.size(),mask=0,ans=0;
        unordered_map<int,int>mp;
        mp[mask]=-1;
        for(int i=0;i<n;i++){
            mask^=(1<<(s[i]-'0'));
            if(mp.find(mask)!=mp.end()) ans=max(ans,i-mp[mask]);
            for(int j=0;j<10;j++){
                if(mp.find(mask^(1<<j))!=mp.end()) ans=max(ans,i-mp[mask^(1<<j)]);
            }
            if(mp.find(mask)==mp.end()) mp[mask]=i;
        }
        return ans;
    }
};