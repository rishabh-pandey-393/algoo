class Solution {
public:
    bool ff(int x, long int y){
        long int pow=1;
        while(pow<y) pow*=x;
        return (pow==y);
    }

    int f(string &s,int ind){
        if(ind==s.size()) return 0;
        if(s[ind]=='0') return 100;
        long long x=0;
        int ans=100;
        for(int i=ind;i<s.size();i++){
            x*=2;
            if(s[i]=='1') x+=1;
            if(ff(5,x)) ans=min(ans,1+f(s,i+1)); 
        }
        return ans;
    }
    
    int minimumBeautifulSubstrings(string s) {
        if(s[0]=='0') return -1;
        int ans=f(s,0);
        if(ans>17) return -1;
        else return ans;
    }
};