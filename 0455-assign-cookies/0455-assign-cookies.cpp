class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=0, j=0;
        int G = g.size();
        int S = s.size();
        int count = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                // If the current cookie can satisfy the current child's greed
                count++;
                i++; // Move to the next child
            }
            // Move to the next cookie in both cases (whether it was used or
            // not)
            j++;
        }
        return count;
    }
};