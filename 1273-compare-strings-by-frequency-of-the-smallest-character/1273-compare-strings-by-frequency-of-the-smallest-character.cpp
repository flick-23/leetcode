class Solution {
public:
    int frequency(const string& s) {
        char ch = 'z';
        vector<int> hash(26, 0);

        // Fill the hash array with frequencies of characters
        for (char c : s) {
            hash[c - 'a']++;
            if (c < ch) {
                ch = c;
            }
        }

        // Return the frequency of the smallest character
        return hash[ch - 'a'];
    }

    vector<int> numSmallerByFrequency(vector<string>& queries,
                                      vector<string>& words) {
        vector<int> fQ, fW;
        vector<int> ans;

        // Calculate frequency counts for each query
        for (const auto& query : queries) {
            fQ.push_back(frequency(query));
        }

        // Calculate frequency counts for each word
        for (const auto& word : words) {
            fW.push_back(frequency(word));
        }

        // Sort the word frequency counts
        sort(fW.begin(), fW.end());

        // For each query frequency, count words with greater frequency
        for (int qCount : fQ) {
            auto ub = upper_bound(fW.begin(), fW.end(), qCount);
            ans.push_back(fW.end() - ub);
        }

        return ans;
    }
};