class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        int count=n;
        if(flowerbed.size()==1&&(flowerbed[0]==0&&n==1)){
            return true;
        }
        for(int i=0;i<flowerbed.size();i++){
            if(i==0&&(flowerbed[i]==0&&flowerbed[i+1]==0)){
                 flowerbed[i]=1;
                 count--;
                 if(count==0) return true;
            }
            else if((i!=0&&i==flowerbed.size()-1)&&(flowerbed[i]==0&&flowerbed[i-1]==0)){
                 flowerbed[i]=1;
                 count--;
                 if(count==0) return true;
            }
            else if(i!=0&&i<flowerbed.size()-1&&flowerbed[i]==0&&(flowerbed[i-1]==0&&flowerbed[i+1]==0)){
            
                flowerbed[i]=1;
                count--;
                if(count==0) return true;
            
        } 
        }
        return false; 
    }
};