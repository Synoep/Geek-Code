class Solution {
public:
    int findDelayTime(int V, vector<vector<int>> &times, int src) {
        vector<vector<pair<int, int>>> adj(V);
        for (auto& time : times) {
            int u = time[0], v = time[1], w = time[2];
            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;
                if (time + weight < dist[nextNode]) {
                    dist[nextNode] = time + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        int maxi = 0;
        for (int i = 0; i <V; i++) {
            if (dist[i] == INT_MAX) return -1;
            maxi = max(maxi, dist[i]);
        }
        return maxi;
    }
};
