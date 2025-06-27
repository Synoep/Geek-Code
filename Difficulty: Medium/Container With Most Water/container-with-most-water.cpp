class Solution {

  public:
    int maxWater(vector<int> &height) {
        // code here
         int maxi=0;
        int left=0;
        int right=height.size()-1;
        while (left<right) {
            maxi=max(maxi,(right-left)*min(height[left], height[right]));
            if (height[left] < height[right]) left++;
            else right--;
        }
        return maxi;  
    }
};