class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n=s.size();
        int mask=0,ans=0;
        unordered_map<char,int>mp;
        unordered_map<int,int>index;
        index[0]=-1;
        mp['a']=0;
        mp['e']=1;
        mp['i']=2;
        mp['o']=3;
        mp['u']=4;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end()) mask^=(1<<mp[s[i]]);
            if(index.find(mask)!=index.end()) ans=max(ans,i-index[mask]);
            if(index.find(mask)==index.end()) index[mask]=i;
        }
        return ans;
    }
};