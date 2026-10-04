class DSU {
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if(parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    bool unite(int u, int v) {

        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv)
            return false;

        if(rank[pu] < rank[pv])
            parent[pu] = pv;

        else if(rank[pv] < rank[pu])
            parent[pv] = pu;

        else {
            parent[pv] = pu;
            rank[pu]++;
        }

        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        DSU ds(n);

        int components = n;

        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            if(ds.unite(u, v))
                components--;
        }

        return components;
    }
};