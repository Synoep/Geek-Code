class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if (n%k!=0) return false;
        map<int,int> freq;
        for (int num :arr) {
            freq[num]++;
        }
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            int num = it->first;
            int count = it->second;
            if (count == 0) continue;

            for (int i = 1; i < k; ++i) {
                int next = num + i;
                if (freq[next] < count) return false;
                freq[next] -= count;
            }
        }

        return true;
    }
};