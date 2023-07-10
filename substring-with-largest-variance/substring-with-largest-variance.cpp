class Solution {
public:
    int largestVariance(string s) {
        int n=s.size(),ans=0;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(i==j) continue;
                int ct=0;
                bool firstb=false,hasb=false;
                for(int k=0;k<n;k++){
                    if(s[k]-'a'==i) ct++;
                    else if(s[k]-'a'==j){
                        hasb=true;
                        if(firstb && ct>=0) firstb=false;
                        else if(--ct<0){
                            firstb=true;
                            ct=-1;
                        }
                    }
                    ans=max(ans,hasb?ct:0);
                }
            }
        }
        return ans;
    }
};