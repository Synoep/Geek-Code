class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        int count=0;
        unordered_map<char,int> mp;
        for(int i=0;i<k;i++) mp[s[i]]++; 
        if(mp.size()==k-1) count++;
        for(int i=k;i<s.size();i++) {
            char ind=s[i-k];
            mp[ind]--;
            if(mp[ind]==0) mp.erase(ind);
            mp[s[i]]++;
            if(mp.size()==k-1) count++;
        }
        return count;
    }
};