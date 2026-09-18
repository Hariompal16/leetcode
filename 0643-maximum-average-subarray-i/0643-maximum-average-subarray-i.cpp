class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        double maxx=sum/(double)k;
        int i=1;
        int j=k;
        while(j<nums.size()){
            sum-=nums[i-1];
            sum+=nums[j];
            double avg=sum/(double)k;
            maxx=max(maxx,avg);
            i++;
            j++;
        
        }
        return maxx;
    }
};