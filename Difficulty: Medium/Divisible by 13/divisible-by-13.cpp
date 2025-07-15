class Solution {
  public:
  
bool is(const string& s) {
    int mod = 0;
    for (char ch:s) {
        mod = (mod*10+(ch-'0'))%13;
    }
    return mod == 0;
}
    bool divby13(string &s) {
        // code here
       if(is(s)) return true;
       return false;
    }
};