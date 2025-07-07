class Solution {
public:
    bool dfs(int src, vector<vector<int>> &adj, vector<int> &vis,vector<int> &df) {
        vis[src]=1;
        df[src]=1;
            for(auto a: adj[src]) {
                if(!vis[a]){
                    if(dfs(a,adj,vis,df)==true) return true;
                }
                else if(df[a]) {
                    return true;
                }
            }
            df[src]=0;
            return false;
        }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto &e : edges) {
            int u = e[0], v =e[1];
            adj[u].push_back(v);
         
        }
        vector<int> vis(V, 0);
        vector<int>df(V,0);
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                if(dfs(i, adj, vis,df)) return true;
            }
        }
        return false;
    }
};
