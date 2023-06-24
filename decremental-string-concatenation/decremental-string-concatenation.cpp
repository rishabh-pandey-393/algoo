class Solution {
public:
    int ff(vector<string>&words,int ind,int f,int l,vector<vector<vector<int>>>&dp){
        if(ind==words.size()) return 0;
        if(dp[ind][f-'a'][l-'a']!=-1) return dp[ind][f-'a'][l-'a'];
        int ans=0;
        if(words[ind][0]==l) ans=max(ans,1+ff(words,ind+1,f,words[ind].back(),dp));
        else ans=max(ans,ff(words,ind+1,f,words[ind].back(),dp));
        if(words[ind].back()==f) ans=max(ans,1+ff(words,ind+1,words[ind][0],l,dp));
        else ans=max(ans,ff(words,ind+1,words[ind][0],l,dp));
        return dp[ind][f-'a'][l-'a']=ans;
    }
    int minimizeConcatenatedLength(vector<string>& words) {
        int n=words.size(),ans=0;
        for(int i=0;i<n;i++) ans+=words[i].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(26,vector<int>(26,-1)));
        return ans-ff(words,1,words[0][0],words[0].back(),dp);
    }
};