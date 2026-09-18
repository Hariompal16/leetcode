class Solution {
public:
    string reverseWords(string s) {
         int k = 0;
     int n =s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                if (k > 0)
                    s[k++] = ' ';

                while (i < n && s[i] != ' ') {
                    s[k++] = s[i];
                    i++;
                }
            }
        }

        s.resize(k);
        int i=0;
        while(i<s.size()){
            if(s[i]==' '){
                i++;
            }
            else{
                int a=i;
                int j=i;
                while( j<s.size()&&s[j]!=' '){
                    j++;
                }
                i=j;
                j--;
                
                while(a<=j){
                    swap(s[a],s[j]);
                    a++;
                    j--;
                }
            }
        }
        reverse(s.begin(),s.end());
        return s;
    }
};