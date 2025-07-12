class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Code here
         vector<vector<pair<int,int>>> adj(n);
        // VIMP algo
        for(auto a:flights){
            int u=a[0];
            int v=a[1];
            int z=a[2];
            adj[u].push_back({v,z});//  next, price
        }
        queue<pair<int, pair<int, int>>> pq; // cost, source , k
        pq.push({0,{src,0}});
        vector<int> dis(n,1e9);
        dis[src]=0;
        while(!pq.empty()){
            auto it=pq.front();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            pq.pop();
            if(stops>k) continue;
            for(auto a:adj[node]){
                 int nex=a.first;
                 int price=a.second;
                 if(cost+price<dis[nex] && stops<=k){
                    dis[nex]=cost+price;
                    pq.push({stops+1,{nex,cost+price}});
                 }
            }
        }
        if(dis[dst]==1e9) return -1;
        return dis[dst];
    }
};