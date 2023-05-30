class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ct=0,mx=0;
        for(auto x:nums){
            if(ct==0) mx=x;
            if(x==mx) ct++;
            else ct--;
        }
        return mx;
    }
};