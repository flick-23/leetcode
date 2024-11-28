class SnapshotArray {
public:
//snapId, value
    vector<map<int,int>> arr;
    int snapId;
    SnapshotArray(int length) {
        arr.resize(length);
        snapId = 0;
    }
    
    void set(int index, int val) {
        arr[index][snapId] = val;
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        // Find the closest snapId <= snap_id
        auto it = arr[index].upper_bound(snap_id);
        if (it == arr[index].begin()) {
            return 0; // Default value if no snapshot exists for this index
        }
        --it;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */