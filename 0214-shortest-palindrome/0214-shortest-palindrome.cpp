class Solution {
public:
    vector<int> computeZ(string s, int& maxi) {
        int n = s.length(); // Length of the input string
        vector<int> Z(n);   // Initialize the Z-array with size n
        // L and R represent the current "window" [L, R] that matches the prefix
        // of the string
        int L = 0, R = 0;
        for (int i = 1; i < n; i++) {
            // Case 1: i is inside the window [L, R]
            if (i <= R) {
                Z[i] = min(R - i + 1, Z[i - L]);
            }
            // Case 2: Calculate Z[i] by comparing characters starting at s[i]
            // and s[0]
            while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
                Z[i]++;
            }
            // Case 3: If Z[i] extends beyond R, adjust L and R
            if (i + Z[i] - 1 > R) {
                L = i;
                R = i + Z[i] - 1;
            }
            maxi = max(maxi, Z[i]);
        }
        return Z;
    }
    string shortestPalindrome(string s1) {
        int n = s1.length();
        string s2 = s1;
        int maxi = 0;
        reverse(s2.begin(), s2.end());
        string combined = s1 + "$" + s2;
        vector<int> Z = computeZ(combined, maxi);
        int index = 0;
        int maxLen = 0;
        for (int i = n + 1; i < combined.size(); i++) {
            if (Z[i] == (combined.size() - i)) {
                maxLen = Z[i];
                break;
            }
        }

        string suffix = s1.substr(maxLen, s1.length() - maxLen);
        reverse(suffix.begin(), suffix.end());
        return suffix + s1;
    }
};