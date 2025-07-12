class Solution {
  public:
    int d(int i,int j,vector<vector<int>>& mat,vector<vector<int>> &dp){
        if(i<0||j<0||i>=mat.size()||j>=mat[0].size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=d(i-1,j+1,mat,dp);
        int right=d(i,j+1,mat,dp);
        int down=d(i+1,j+1,mat,dp);
        return dp[i][j]=max({up,right,down})+mat[i][j];
    }
    int maxGold(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        int ans =0;
        for (int i=0;i<n;i++) {
            ans=max(ans, d(i,0,mat,dp));
        }
        return ans;
        
    }
};