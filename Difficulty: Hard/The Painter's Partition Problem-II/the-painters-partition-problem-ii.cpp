// User function template for C++

class Solution {
  public:
    int p( vector<int>&nums,int mid){
        int sum=0;
        int a=1;
        for(int i=0;i<nums.size();i++){
           if(sum+nums[i]<=mid){
            sum+=nums[i];
           }
           else{
              a++;
              sum=nums[i];
           }
        }
        return a;
    }
  
    int minTime(vector<int>& nums, int k) {
        // code here
        int low=*max_element(nums.begin(),nums.end());
      int high = accumulate(nums.begin(),nums.end(),0);
      while (low<=high) {
        int mid = (low + high) / 2;
        int count=p(nums, mid);
        if (count>k) low=mid+1;
        else high=mid-1;
    }
     return low;
        // return minimum time
    }
};