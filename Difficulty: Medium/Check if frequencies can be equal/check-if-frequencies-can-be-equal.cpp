class Solution {
  public:
    bool sameFreq(string& s) {
        // code here
        unordered_map<char,int>mp;
        for(auto a:s)mp[a]++;
        unordered_map<int,int>mpp;
        for(auto a:mp) mpp[a.second]++;
        if(mpp.size()==1) return true;
        if(mpp.size()>2) return false;
        auto it=mpp.begin();
        auto it2=next(it);
        int f1 =it->first,c1=it->second;
        int f2 =it2->first,c2=it2->second;
        if ((f1==1&&c1==1)||(f2==1&&c2==1)) return true;
        if (abs(f1-f2)==1) {
        if ((f1>f2 && c1==1) ||(f2>f1 &&c2==1)) return true;
        }
        return false;
    }
};