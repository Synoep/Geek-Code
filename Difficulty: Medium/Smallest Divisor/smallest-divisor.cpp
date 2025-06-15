class Solution {
  public:
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
         int low=1,high=*max_element(arr.begin(), arr.end());
        int ans=high;
        while (low<=high) {
            int mid=low+(high-low)/2;

            int sum =0;
            for (int num:arr) {
                sum +=(num+mid-1)/mid; 
            }
            if (sum<=k) {
                ans=mid;
                high=mid - 1;
            } else low =mid+1;
            }
        return ans;
    }
};
