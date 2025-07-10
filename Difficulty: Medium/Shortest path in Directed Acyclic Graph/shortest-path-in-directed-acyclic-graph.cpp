// User function Template for C++
class Solution {
  public:
    void dfs(int node,vector<vector<pair<int,int>>> &adj,stack<int> &st,vector<int> &vis){
        vis[node]=1;
        for(auto a:adj[node]){
            int v=a.first;
            if(!vis[v]) dfs(v,adj,st,vis);
            
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<E;i++){
            int a=edges[i][0];
            int b=edges[i][1];
            int c=edges[i][2];
            adj[a].push_back({b,c});
        }
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(i,adj,st,vis);
        }
        vector<int>ans(V,1e9);
        vector<int>a(V,-1);
        ans[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(auto a:adj[node]){
                int src=a.first;
                int wt=a.second;
                if(ans[node]+wt<ans[src]) ans[src]=ans[node]+wt;
            }
        }
        for(int i=0;i<V;i++) {
            if(ans[i]!=1e9) a[i]=ans[i];
        }
        return a;
    }
};
