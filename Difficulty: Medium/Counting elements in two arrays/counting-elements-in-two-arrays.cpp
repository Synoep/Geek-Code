class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
       sort(b.begin(),b.end());
       vector<int> v;
       for(int i=0;i<a.size();i++){
           int z=upper_bound(b.begin(),b.end(),a[i])-b.begin();
           v.push_back(z);
       }
       return v;
    }
};