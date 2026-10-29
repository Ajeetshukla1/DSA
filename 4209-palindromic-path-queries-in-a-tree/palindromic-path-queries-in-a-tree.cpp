
class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> tin(n), tout(n), depth(n);
        int timer = 0;

        // Iterative DFS: avoid stack overflow on a long chain.
        vector<int> parent(n, -1), it(n, 0), st = {0};
        parent[0] = 0;
        tin[0] = timer++;

        while (!st.empty()) {
            int u = st.back();

            if (it[u] < (int)adj[u].size()) {
                int v = adj[u][it[u]++];
                if (v == parent[u]) continue;

                parent[v] = u;
                depth[v] = depth[u] + 1;
                tin[v] = timer++;
                st.push_back(v);
            } else {
                tout[u] = timer - 1;
                st.pop_back();
            }
        }

        for (int u = 0; u < n; u++)
            up[0][u] = parent[u];

        for (int j = 1; j < LOG; j++)
            for (int u = 0; u < n; u++)
                up[j][u] = up[j - 1][up[j - 1][u]];

        auto isAncestor = [&](int u, int v) {
            return tin[u] <= tin[v] && tout[v] <= tout[u];
        };

        auto lca = [&](int u, int v) {
            if (isAncestor(u, v)) return u;
            if (isAncestor(v, u)) return v;

            for (int j = LOG - 1; j >= 0; j--) {
                if (!isAncestor(up[j][u], v))
                    u = up[j][u];
            }
            return up[0][u];
        };

        // Fenwick tree for range-XOR updates and point queries.
        vector<int> bit(n + 2, 0);

        auto add = [&](int idx, int val) {
            for (int i = idx + 1; i <= n; i += i & -i)
                bit[i] ^= val;
        };

        auto prefix = [&](int idx) {
            int res = 0;
            for (int i = idx + 1; i > 0; i -= i & -i)
                res ^= bit[i];
            return res;
        };

        auto rangeUpdate = [&](int l, int r, int val) {
            add(l, val);
            if (r + 1 < n) add(r + 1, val);
        };

        auto getMask = [&](int u) {
            return prefix(tin[u]);
        };

        vector<int> mask(n);
        for (int u = 0; u < n; u++) {
            mask[u] = 1 << (s[u] - 'a');
            rangeUpdate(tin[u], tout[u], mask[u]);
        }

        vector<bool> ans;

        for (const string& q : queries) {
            string type;
            int u;
            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int newMask = 1 << (c - 'a');
                int delta = mask[u] ^ newMask;

                // A node's change affects its entire subtree's
                // root-to-node prefix XOR.
                rangeUpdate(tin[u], tout[u], delta);

                mask[u] = newMask;
                s[u] = c;
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);
                int pathMask = getMask(u) ^ getMask(v) ^ mask[w];

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};
