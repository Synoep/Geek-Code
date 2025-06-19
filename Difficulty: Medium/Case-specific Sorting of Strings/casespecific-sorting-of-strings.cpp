class Solution {
  public:
    string caseSort(string& s) {
    vector<char> lower, upper;
    for (char ch:s) {
        if (islower(ch)) lower.push_back(ch);
        else upper.push_back(ch);
    }
    sort(lower.begin(), lower.end());
    sort(upper.begin(), upper.end());
    string result=s;
    int li=0,ui=0;
    for (int i=0;i<s.length();i++) {
        if (islower(s[i])) result[i] = lower[li++];
        else result[i] = upper[ui++];
    }
    return result;
    }
};