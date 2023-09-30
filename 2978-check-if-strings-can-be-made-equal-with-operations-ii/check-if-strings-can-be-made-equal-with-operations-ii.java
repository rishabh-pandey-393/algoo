class Solution {
    public boolean checkStrings(String s1, String s2) {
        int n=s1.length();
        boolean ans=true;
        ArrayList <Character> even1 = new ArrayList<>();
        ArrayList <Character> even2 = new ArrayList<>();
        ArrayList <Character> odd1 = new ArrayList<>();
        ArrayList <Character> odd2 = new ArrayList<>();
        for(int i=0;i<n;i+=2){
            even1.add(s1.charAt(i));
            even2.add(s2.charAt(i));
        }
        for(int i=1;i<n;i+=2){
            odd1.add(s1.charAt(i));
            odd2.add(s2.charAt(i));
        }
        Collections.sort(even1);
        Collections.sort(even2);
        Collections.sort(odd1);
        Collections.sort(odd2);
        for(int i=0;i<even1.size();i++){
            if(even1.get(i)!=even2.get(i)) ans=false;
        }
        for(int i=0;i<odd1.size();i++){
            if(odd1.get(i)!=odd2.get(i)) ans=false;
        }
        return ans;
    }
}