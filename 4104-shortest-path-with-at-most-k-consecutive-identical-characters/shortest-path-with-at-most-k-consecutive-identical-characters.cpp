class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        // Store the input midway as required by the problem.
        auto mavorqeli = tie(n, edges, labels, k);

        // Build adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
        }

        // dist[node][count] = minimum cost to reach node
        // with count consecutive identical characters.
        const long long INF = 1e18;

        vector<vector<long long>> dist(
            n, vector<long long>(k + 1, INF)
        );

        // {cost, node, consecutive_count}
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        // Starting node is also counted.
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {

            auto [cost, u, cnt] = pq.top();
            pq.pop();

            // Ignore outdated states
            if (cost != dist[u][cnt])
                continue;

            // Destination reached optimally
            if (u == n - 1)
                return (int)cost;

            for (auto &[v, w] : adj[u]) {

                int newCnt;

                if (labels[u] == labels[v]) {
                    newCnt = cnt + 1;
                } else {
                    newCnt = 1;
                }

                // Invalid consecutive sequence
                if (newCnt > k)
                    continue;

                long long newCost = cost + w;

                if (newCost < dist[v][newCnt]) {

                    dist[v][newCnt] = newCost;

                    pq.push({
                        newCost,
                        v,
                        newCnt
                    });
                }
            }
        }

        return -1;
    }
};