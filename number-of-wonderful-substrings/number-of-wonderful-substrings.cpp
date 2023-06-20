class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long n=word.size(),mask=0,ans=0;
        unordered_map<long long,int>mp;
        mp[mask]=1;
        for(int i=0;i<n;i++){
            mask^=(1<<(word[i]-'a'));
            ans+=mp[mask];
            for(int j=0;j<11;j++) ans+=mp[mask^(1<<j)];
            mp[mask]++;
        }
        return ans;
    }
};