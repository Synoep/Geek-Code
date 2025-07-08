class Solution {
  public:
    bool dfs(int node,int col,vector<int> &color,vector<vector<int>> &adj){
        color[node]=col;
        for(auto a:adj[node]){
            if(color[a]==-1){
                if(dfs(a,!col,color,adj)==false )return false;
            }
            else if(color[a]==col) return false;
        }
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto a:edges){
           int u=a[0];
           int v=a[1];
           adj[u].push_back(v);
           adj[v].push_back(u);
       }
       vector<int> color(V,-1);
       for(int i=0;i<V;i++){
           if(color[i]==-1) {
               if(dfs(i,0,color,adj)==false) return false;
           }
       }
       return true;
    }
};