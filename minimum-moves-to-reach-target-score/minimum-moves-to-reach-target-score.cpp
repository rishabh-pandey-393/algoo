class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans=0;
        while(target!=1){
            if(target%2==1) target--;
            else {
                if(maxDoubles>0) {
                    target/=2;
                    maxDoubles--;
                }
                else return ans+target-1;
            }
            ans++;
        }
        return ans;
    }
};