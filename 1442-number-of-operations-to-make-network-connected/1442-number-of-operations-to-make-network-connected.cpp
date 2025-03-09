class DisjointSet{
    public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n+1);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0; i <=n; i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUParent(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int parentU = findUParent(u);
        int parentV = findUParent(v);
        //both belong to same parent
        if(parentU == parentV)
            return;
        //both belong to different parent - attach the smaller size component to bigger size component
        if(size[parentU] < size[parentV]){
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        } else{
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int countExtras = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUParent(u) == ds.findUParent(v)){
                countExtras++;
            } else{
                ds.unionBySize(u,v);
            }
        }
        int numberOfComponents = 0;
        for(int i = 0; i < n; i++){
            if(ds.parent[i] == i)
                numberOfComponents++;
        }
        int ans = numberOfComponents-1;
        if(countExtras>=ans)
            return ans;
        return -1;
    }
};