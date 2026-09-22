class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int s=0;
        int e=1;
        while(e<nums.size()){
            if(nums[s]==nums[e]){
                e++;
            }
            else{
                nums[s+1]=nums[e];
                s++;
                e++;
            }
        }
        return s+1;
    }
};