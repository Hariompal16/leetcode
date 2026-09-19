class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int count=0;
        while(j<nums.size()&&count){
           if(nums[j]==0){
            count--;
           }
           j++;
        }
        int maxx=j-i;
        while(j<nums.size()){
           if(nums[j]==1){
            j++;
           }
           else if(nums[j]==0&&count<k){
            count++;
            j++;
           }
           else{
            if(nums[i]==0){
                count--;
                
            }
            i++;
           }
            
      maxx=max(maxx,j-i);
            
        }
        return maxx;
    }
};