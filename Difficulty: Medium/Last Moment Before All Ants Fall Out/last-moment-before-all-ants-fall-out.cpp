class Solution {
  public:
int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
    int maxi=0;
    for (int pos:left) {
        maxi=max(maxi,pos);
    }
    for (int pos:right) {
        maxi= max(maxi,n-pos); 
    }
    
    return maxi;
    }
};