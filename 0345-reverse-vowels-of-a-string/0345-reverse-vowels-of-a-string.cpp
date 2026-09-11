class Solution {
public:
bool vowel(char s){
    return s=='a'||s=='e'||s=='i'||s=='o'||s=='u'||s=='A'||s=='E'||s=='I'||s=='O'||s=='U';
}
    string reverseVowels(string s) {
        string ss;
        for(int i=0;i<s.size();i++){
            if(vowel(s[i])){
                ss+=s[i];
            }
        }
        reverse(ss.begin(),ss.end());
        int j=0;
        for(int i=0;i<s.size();i++){
            if(vowel(s[i])){
                s[i]=ss[j];
                j++;
            }
        }
        return s;
    }
};