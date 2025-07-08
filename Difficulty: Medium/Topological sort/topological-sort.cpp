class Solution {
  public:
    // khans algo 
    void dfs(int node,vector<vector<int>>& adj,stack<int> &st,vector<int> &vis){
        vis[node]=1;
        for(auto a:adj[node]){
            if(!vis[a]) dfs(a,adj,st,vis);
            
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto a:edges){
            int u=a[0],v=a[1];
            adj[u].push_back(v);
        }
        stack<int>st;
        vector<int>vis(V,0);
        // dfs(1,adj,st,vis);
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(i,adj,st,vis);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};