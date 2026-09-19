class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int count=0;
        int maxx=INT_MIN;

        while(j<nums.size()){
            if(nums[j]==1){
                j++;
            }
            else if(nums[j]==0&&count!=1){
                j++;
                count=1;
            }
            else{
                if(nums[i]==0&&count!=0){
                  
                   count=0;
                }
                 i++;
            }
            maxx=max(maxx,j-i);
        }
        if(maxx==INT_MIN) return 0;
        return maxx-1;
    }
};