class Solution {
public:
    bool solve(int value, map<int, int>& mpp, int size) {
        for (int i = 0; i < size; i++) {
            if (mpp.count(value + i) > 0) {
                mpp[value + i]--;
                if (mpp[value + i] == 0) {
                    mpp.erase(value + i);
                }
            } else {
                return false;
            }
        }
        return true;
    }
    bool isPossibleDivide(vector<int>& nums, int groupSize) {
        int n = nums.size();
        //<number, count≥
        map<int, int> mpp;
        for (int i : nums) {
            mpp[i]++;
        }
        int i = 0;
        while (!mpp.empty()) {
            auto it = mpp.begin();
            int value = it->first;
            if (solve(value, mpp, groupSize)) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};