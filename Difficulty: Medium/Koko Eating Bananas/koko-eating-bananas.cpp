class Solution {
  public:
  bool c(const vector<int>& arr, int k, int speed) {
    int hours =0;
    for (int bananas:arr) {
        hours += (bananas+speed-1)/speed;  
    }
    return hours <= k;
}
    int kokoEat(vector<int>& arr, int k) {
        // Code here
         int left = 1, right = *max_element(arr.begin(), arr.end());
         int result = right;

         while (left <= right) {
           int mid = left + (right - left) / 2;
  
          if (c(arr, k, mid)) {
            result = mid;
            right = mid - 1;
        }   else {
            left = mid + 1;    
        }
    }

    return result;        
    }
};