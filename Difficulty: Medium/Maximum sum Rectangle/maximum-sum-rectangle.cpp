// User function Template for C++

class Solution {
  public:
    int k(vector<int> &temp){
        int cur=temp[0];
        int maxi=temp[0];
        for(int i=1;i<temp.size();i++){
            cur=max(temp[i],cur+temp[i]);
            maxi=max(cur,maxi);
        }
        return maxi;
    }
    int maximumSumRectangle(vector<vector<int>> &matrix) {
        // code here
        int maxi=INT_MIN;
        int n= matrix.size();
        int m=matrix[0].size();
        for(int l=0;l<m;l++){
            vector<int>temp(n,0);
            for(int r=l;r<m;r++){
                for(int i=0;i<n;i++){
                    temp[i]+=matrix[i][r];
                }
                int cur=k(temp);
                maxi=max(cur,maxi);
            }
        }
        return maxi;
    }
};
