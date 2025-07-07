class Solution {
  public:
    bool dfs(int node,int parent,vector<int> &vis,vector<vector<int>> &adj){
        vis[node]=1;
        for(auto a:adj[node]){
            if(!vis[a]) {
                if(dfs(a,node,vis,adj)==true) return true;
            }
            else if(a!=parent) return true; 
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
       vector<vector<int>>adj(V);
       for(auto a:edges){
           int u=a[0];
           int v=a[1];
           adj[u].push_back(v);
           adj[v].push_back(u);
       }
       vector<int> vis(V,0);
       for(int i=0;i<V;i++){
           if(!vis[i]) if(dfs(i,-1,vis,adj)==true) return true;
       }
       return false;
    }
};