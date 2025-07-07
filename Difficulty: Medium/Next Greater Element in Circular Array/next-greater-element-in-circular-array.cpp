class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        int n = arr.size();
       vector<int> result(n, -1);
        stack<int> st;  

      for (int i=2*n-1;i>=0;i--) {
        int curr=arr[i%n];
        while (!st.empty()&&arr[st.top()]<=curr) st.pop();
        
        if (i<n) {
            if (!st.empty())
                result[i]=arr[st.top()];
        }
        st.push(i%n);
    }
    return result;
    }
};