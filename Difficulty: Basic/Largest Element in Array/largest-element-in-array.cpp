class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int m=*max_element(arr.begin(),arr.end());
        return m;
    }
};
