class Solution {
public:
    int maxArea(vector<int>& height) {
          int i=0;
          int j=height.size()-1;
          int maxx=INT_MIN;
          while(i<j){
             int minn=min(height[i],height[j]);
             maxx=max(maxx,minn*(j-i));
             if(height[i]<height[j]){
                i++;
             }
             else{
                j--;
             }
    }
    return maxx;
    }
};