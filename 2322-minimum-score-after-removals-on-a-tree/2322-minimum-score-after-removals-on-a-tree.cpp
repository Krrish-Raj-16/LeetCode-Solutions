class Solution {
public:
    int dfs(int u, int parent, const vector<int>& values, const vector<vector<int>>& adj, vector<int>& xor_subtree, vector<int>& par) {
        int xor_sum = values[u];
        par[u] = parent;
        for (int v : adj[u]) {
            if (v != parent) xor_sum ^= dfs(v, u, values, adj, xor_subtree, par);
        }
        xor_subtree[u] = xor_sum;
        return xor_sum;
    }
     bool isAncestor(int u, int v, const vector<int>& par) {
        int cur = v;
        while (cur != -1) {
            if (cur == u) return true;
            cur = par[cur];
        }
        return false;
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> xr(n);
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> par(n, -1);
        dfs(0, -1, nums, adj, xr, par);
        int totalXor = xr[0];
        int res = 1e9;
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a, b, c;
                if (isAncestor(i, j, par)) {
                    a = xr[j];
                    b = xr[i] ^ xr[j];
                    c = totalXor ^ xr[i];
                } else if (isAncestor(j, i, par)) {
                    a = xr[i];
                    b = xr[j] ^ xr[i];
                    c = totalXor ^ xr[j];
                } else {
                    a = xr[i];
                    b = xr[j];
                    c = totalXor ^ xr[i] ^ xr[j];
                }
                int mx = max({a, b, c});
                int mn = min({a, b, c});
                res = min(res, mx - mn);
            }
        }
        return res;
    }
   
};
