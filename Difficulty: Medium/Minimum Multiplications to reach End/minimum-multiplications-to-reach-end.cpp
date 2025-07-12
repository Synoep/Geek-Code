// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int, int>> q;
        if(start==end) return 0;
        q.push({start,0});
        vector<int> dist(100000, 1e9);
        dist[start]=0;
        int mod=100000;
        while(!q.empty()){
            int node=q.front().first;
            int count=q.front().second;
            q.pop();
            for(auto a:arr){
                int num=(node*a) %mod;
                if(count+1<dist[num]){
                    dist[num]=count+1;
                    if(num==end) return count+1;
                    q.push({num,count+1});
                }
            }
        }
        return -1;
    }
};
