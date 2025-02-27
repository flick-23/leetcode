class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        unordered_map<char, int> freq;
        priority_queue<pair<int, char>> pq;
        for (char ch : s) {
            freq[ch]++;
            // Impossible to reorganize if a any char is
            if (freq[ch] > ((n + 1) / 2)) {
                return "";
            }
        }
        for (auto& entry : freq) {
            pq.push({entry.second, entry.first});
        }
        string ans = "";
        pair<int, char> prev = {0, '#'}; // Placeholder
        while (!pq.empty()) {
            auto [num, ch] = pq.top();
            pq.pop();
            ans += ch;
            if (prev.first > 0) {
                pq.push(prev); // Reinsert the previous char if any
            }
            prev = {num - 1, ch}; // Reduce count and store previous
        }
        return ans;
    }
};