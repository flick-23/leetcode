class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> m;
        int j = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (m.size() < 2 || m.find(fruits[i]) != m.end()) {
                m[fruits[i]]++;
            } else {
                while (m.size() != 1) {
                    m[fruits[j]]--;
                    if (m[fruits[j]] == 0) {
                        m.erase(fruits[j]);
                    }
                    j++;
                }
                m[fruits[i]]++;
            }
            int sum = 0;
            for (auto pr : m) {
                sum += pr.second;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};