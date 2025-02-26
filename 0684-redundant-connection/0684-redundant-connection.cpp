class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUParent(int node) {
        if (node == parent[node])
            return node;
        // path compression - used to find parent in O(1) time,
        // eliminating the sub parents and directly connecting to ultimate
        // Parent
        return parent[node] = findUParent(parent[node]);
    }
    bool unionBySize(int u, int v) {
        int parentU = findUParent(u);
        int parentV = findUParent(v);
        // both belong to same parent
        if (parentU == parentV)
            return true; // Cycle detected, return true
        // both belong to different parent - attach the smaller size component
        // to bigger size component
        if (size[parentU] < size[parentV]) {
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        } else {
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
        return false;   // No cycle detected
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            if(ds.unionBySize(u,v)){
                return edge;
            }
        }
        return {};
    }
};