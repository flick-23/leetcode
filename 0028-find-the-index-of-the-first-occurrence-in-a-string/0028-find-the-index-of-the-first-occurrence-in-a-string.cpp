class Solution {
public:
    vector<int> computeZ(string str) {
        int n = str.length();
        vector<int> Z(n, 0); // Initialize Z array with zeros

        // Initialize the left and right boundaries of the current "box"
        int L = 0, R = 0;

        for (int i = 1; i < n; ++i) {
            if (i > R) {
                // Case 1: i is outside the current "box"
                L = R = i; // Set both L and R to i
                // Extend the "box" to the right as long as the characters match
                while (R < n && str[R] == str[R - L]) {
                    R++;
                }
                Z[i] = R - L; // The length of the match is R - L
                R--;          // Adjust R to the last matching position
            } else {
                // Case 2: i is inside the current "box"
                int k = i - L; // Calculate the position k within the "box"
                if (Z[k] < R - i + 1) {
                    Z[i] = Z[k]; // Copy the Z value from position k
                } else {
                    L = i; // Move the left boundary of the "box" to i
                    while (R < n && str[R] == str[R - L]) {
                        R++;
                    }
                    Z[i] = R - L; // The length of the match is R - L
                    R--;          // Adjust R to the last matching position
                }
            }
        }
        return Z;
    }
    int strStr(string haystack, string needle) {
        string combined = needle + "$" + haystack;
        vector<int> Z = computeZ(combined);
        for (int i : Z) {
            cout << i << " ";
        }
        int len = needle.size();
        for (int i = 0; i < Z.size(); i++) {
            if (len == Z[i]) {
                return (i - len - 1);
            }
        }
        return -1;
    }
};