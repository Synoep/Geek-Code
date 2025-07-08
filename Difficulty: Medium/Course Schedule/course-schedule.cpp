class Solution {
  public:
   bool dfs(int node,vector<vector<int>> &adj,vector<int> &vis,vector<int> &df,stack<int> &st){
         vis[node]=1;
         df[node]=1;
         for(auto a:adj[node]){
            if(vis[a]==0){
                if(dfs(a,adj,vis,df,st)==true) return true;
            }
            else if(df[a]==1) return true;
         }
         df[node]=0;
         st.push(node);
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>> p) {
        // code here
        vector<vector<int>> adj(n);
        for(auto a: p){
            int u=a[0],v=a[1];
            adj[u].push_back(v);
        }
        stack<int> st;
        vector<int> vis(n,0);
        vector<int> df(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(dfs(i,adj,vis,df,st)) return {};
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};