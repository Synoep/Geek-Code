// User function Template for C++

class Solution {
  public:
    bool dfs(int src, vector<int> adj[], vector<int> &vis,vector<int> &df,vector<int> &check) {
        vis[src]=1;
        df[src]=1;
            for(auto a: adj[src]) {
                if(!vis[a]){
                    if(dfs(a,adj,vis,df,check)==true){
                         check[src]=0;
                         return true;
                    }
                }
                else if(df[a]) {
                    check[src]=0;
                    return true;
                }
            }
            df[src]=0;
            check[src]=1;
            return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V, 0);
        vector<int>df(V,0);
        vector<int>check(V,0);
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                dfs(i, adj, vis,df,check);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(check[i]==1)ans.push_back(i);
        }
       return ans;
    }
};
