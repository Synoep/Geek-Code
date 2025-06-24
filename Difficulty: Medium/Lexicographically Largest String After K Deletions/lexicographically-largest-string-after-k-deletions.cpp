class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        string result;
        for(auto a:s){
            while(k!=0&&!result.empty()&&result.back()<a){
                result.pop_back();
                k--;
            }
            result.push_back(a);
        }
        while(k>0){
            result.pop_back();
            k--;
        }
        return result;
    }
};
