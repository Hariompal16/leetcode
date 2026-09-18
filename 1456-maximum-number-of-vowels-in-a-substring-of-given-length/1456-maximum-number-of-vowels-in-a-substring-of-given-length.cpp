class Solution {
public:
    int maxVowels(string s, int k) {
        int count=0;
        for(int i=0;i<k;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                count++;
            }
        }
        int maxx=count;
        int i=1;
        int j=k;
        while(j<s.size()){
            if(s[i-1]=='a'||s[i-1]=='e'||s[i-1]=='i'||s[i-1]=='o'||s[i-1]=='u'){
                count--;
            }
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'){
                count++;
            }
            maxx=max(maxx,count);
            j++;
            i++;
        }
        return maxx;
            
    }
};