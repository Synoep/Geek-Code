class Solution {
  public:
    int countConsec(int n) {
        // code here
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=2;
    for (int i=2;i<=n;i++) {
        dp[i]=dp[i-1]+dp[i-2];
    }
    int total =1 << n;
    int a= dp[n];

    return total-a;
    }
};