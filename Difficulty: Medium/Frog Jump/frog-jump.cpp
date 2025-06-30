class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        vector<int>dp(height.size(),-1);
        dp[0]=0;
        for(int ind=1;ind<height.size();ind++){
            int j2=INT_MAX;
            int j1=dp[ind-1] + abs(height[ind]-height[ind-1]);
            if(ind>1)  j2=dp[ind-2] + abs(height[ind]-height[ind-2]);
            dp[ind]=min(j1,j2);
        }
        return dp[height.size()-1];
    }
};