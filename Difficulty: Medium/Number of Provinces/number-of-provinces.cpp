// User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<int> &vis,vector<vector<int>>&adj) {
        vis[node]=1;
        for (auto a:adj[node]) {
            if (!vis[a]) {
                dfs(a,vis,adj);
            }
        }
    }
    int numProvinces(vector<vector<int>> edges, int V) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(edges[i][j]==1) adj[i].push_back(j);
            }
        }
        vector<int> vis(V, 0);
        int count=0;
        for (int i=0;i<V;i++) {
            if (!vis[i]) {
                count++;              
                dfs(i,vis,adj);
            }
        }
        return count;
        
    }
};