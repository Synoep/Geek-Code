// Function to locate the occurrence of the string x in the string s.
class Solution {
  public:
    int firstOccurence(string &txt, string &pat) {
        // Your code here
        int a=txt.length();
        int b=pat.length();
        for(int i=0;i<=a-b;i++){
            if(txt.substr(i,b)==pat) return i;
        }
        return -1;
    }
};