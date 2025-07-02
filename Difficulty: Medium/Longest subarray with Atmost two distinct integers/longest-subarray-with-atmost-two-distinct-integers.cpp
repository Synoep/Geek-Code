class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        unordered_map<int,int>mp;
        int maxi=0;
        int start=0;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
            while(mp.size()>2){
                mp[arr[start]]--;
                if(mp[arr[start]]==0) mp.erase(arr[start]);
                start++;
            }
            maxi=max(maxi,i-start+1);
        }
        return maxi;
    }
};