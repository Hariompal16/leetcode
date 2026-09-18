class Solution {
public:
    int compress(vector<char>& chars) {
        string a;
        int i=0;
        if(chars.size()==1){
            return 1;
        }
        while(i<chars.size()){
            int count=0;
            char s;
           
                 s=chars[i];
                count=1;
            
            
                while(i<chars.size()&&s==chars[i]){
                    count++;
                    i++;

                }
                 count--;
                a+=s;
                if(count!=1)
                a+=to_string(count);
                s=' ';
                count=0;
            
        }

        for(int i=0;i<a.size();i++){
            chars[i]=a[i];
        }
        return a.size();
    }
};