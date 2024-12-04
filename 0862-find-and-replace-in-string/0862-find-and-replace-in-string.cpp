class Solution {
public:
    string findReplaceString(string s, vector<int>& indices,
                             vector<string>& sources, vector<string>& targets) {
        int n = indices.size();
        // Step 1: Combine indices, sources, and targets, and sort by indices
        vector<tuple<int, string, string>> replacements;
        for (int i = 0; i < n; i++) {
            replacements.push_back({indices[i], sources[i], targets[i]});
        }
        sort(replacements.begin(), replacements.end());

        // Step 2: Apply replacements
        string ans = "";
        int last = 0; // Pointer to keep track of unprocessed characters in `s`
        for (auto [index, source, target] : replacements) {
            // Add unprocessed characters before the current index
            while (last < index) {
                ans += s[last];
                last++;
            }

            // Check if the substring at `index` matches `source`
            if (s.substr(index, source.length()) == source) {
                ans += target;           // Replace it with `target`
                last += source.length(); // Skip the replaced portion
            }
        }

        // Step 3: Add remaining characters from `s`
        ans += s.substr(last);

        return ans;
    }
};