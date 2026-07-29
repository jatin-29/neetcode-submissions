class Solution {

private:

    bool dfs(int node, int parent,
             vector<vector<int>>& adj,
             vector<bool>& visited) {

        visited[node] = true;

        for (int nbr : adj[node]) {

            if (!visited[nbr]) {

                if (!dfs(nbr, node, adj, visited))
                    return false;
            }

            // Cycle found
            else if (nbr != parent) {
                return false;
            }
        }

        return true;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {

        // Tree must have exactly n-1 edges
        if (edges.size() != n - 1)
            return false;

        vector<vector<int>> adj(n);

        for (auto &e : edges) {

            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);

        if (!dfs(0, -1, adj, visited))
            return false;

        // Check all nodes are connected
        for (int i = 0; i < n; i++) {

            if (!visited[i])
                return false;
        }

        return true;
    }
};


// tree ki property cycle nhi honi chahiye dusra every node connected 