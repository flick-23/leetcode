class Solution {
public:
    bool isValid(string& s, int i) {
        return !(i >= 1 && s[i] == s[i - 1]) && !(i >= 2 && s[i] == s[i - 2]);
    }

    string smallestBeautifulString(string s, int p) {
        int n = s.size();

        // Step 1: Try incrementing from the last character
        for (int i = n - 1; i >= 0; i--) {
            s[i]++; // Increment character

            // Ensure it is within bounds ('a' to 'a' + p - 1)
            while (s[i] >= 'a' + p || !isValid(s, i)) {
                s[i]++; // Keep incrementing until it is valid
                if (s[i] >= 'a' + p) {
                    break; // If we exceed, move left
                }
            }

            // Step 2: If we found a valid character, fix the rest
            if (s[i] < 'a' + p) {
                for (int j = i + 1; j < n; j++) {
                    s[j] = 'a'; // Reset remaining to the smallest possible
                    while (!isValid(s, j)) {
                        s[j]++; // Ensure validity
                    }
                }
                return s; // Valid lexicographically smallest string found
            }
        }

        return ""; // No valid string found
    }
};