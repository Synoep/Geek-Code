class Solution {
  public:

    char f(unordered_map<char, int>& mp) {
        int maxi=0;
        char z=0;
        for (auto a:mp) {
            if (a.second>maxi) {
                maxi=a.second;
                z =a.first;
            }
        }
        return z;
    }

    int minValue(string &s,int k) {
        unordered_map<char,int> mp;
        for (auto a:s) {
            mp[a]++;
        }
        while (k--) {
            char c=f(mp);
            mp[c]--;
        }
        int sum =0;
        for (auto a:mp) {
            sum +=a.second*a.second;
        }
        return sum;
    }
};
