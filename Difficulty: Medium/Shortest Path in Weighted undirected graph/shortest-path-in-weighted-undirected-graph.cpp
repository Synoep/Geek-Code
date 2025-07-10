class Solution {
  public:
    vector<int> shortestPath(int V, int m, vector<vector<int>>& edges) {
        // Code here
        int nn=1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(V+1,1e9);
        dis[nn]=0;
        vector<int> parent(V+1,0);
        vector<vector<pair<int,int>>> adj(V+1);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            int c=edges[i][2];
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        pq.push({0,nn});// dist,node
        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto a:adj[node]){
                int src=a.first;
                int wt=a.second;
                if(dis[node]+wt<dis[src]) {
                    dis[src]=dis[node]+wt;
                    pq.push({dis[src],src});
                    parent[src]=node;
                }
            }
        }
       if (dis[V]==1e9) return {-1};
        vector<int> path;
        int node =V;
        while (parent[node] !=node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(nn);
        reverse(path.begin(), path.end());
        vector<int> result = {dis[V]};
        result.insert(result.end(), path.begin(), path.end());
        return result;

    }
};