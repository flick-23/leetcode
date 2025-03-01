class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0)
            return 0;

        // Step 1: Sort envelopes by width, and by height in descending order
        // when widths are the same
        sort(envelopes.begin(), envelopes.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
             });

        // Step 2: Apply LIS on the heights
        vector<int> lis;
        for (auto& envelope : envelopes) {
            int h = envelope[1];
            auto it = lower_bound(lis.begin(), lis.end(), h);

            if (it == lis.end()) {
                lis.push_back(h); // Extend the LIS
            } else {
                *it = h; // Replace to maintain the smallest possible sequence
            }
        }

        return lis.size();
    }
};
