class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int i=0,candy=n;
        while(i<n-1){
            if(ratings[i]==ratings[i+1]) {
                i++;
                continue;
            }
            int peak=0;
            while(i<n-1 && ratings[i]<ratings[i+1]){
                peak++;
                candy+=peak;
                i++;
            } 
            int valley=0;
            while(i<n-1 && ratings[i]>ratings[i+1]){
                valley++;
                candy+=valley;
                i++;
            }
            candy-=min(peak,valley);
        }
        return candy;
    }
};