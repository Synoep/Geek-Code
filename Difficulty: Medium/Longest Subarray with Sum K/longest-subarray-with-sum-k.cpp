class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int , int >mp;
        int sum=0;
        int maxi=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==k) maxi=max(maxi,i+1);
            int req=sum-k;
            if(mp.find(req)!=mp.end()){
                int len=i-mp[req];
                maxi=max(maxi,len);
            }
            if(mp.find(sum)==mp.end()) mp[sum]=i;
        }
        return maxi;
    }
};