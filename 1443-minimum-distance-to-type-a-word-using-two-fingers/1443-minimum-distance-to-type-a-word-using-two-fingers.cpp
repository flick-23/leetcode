class Solution {
public:
    int n;
    map<char, pair<int, int>> mp;
    typedef pair<int, int> pi;
    map<pair<int, pair<pi, pi>>, int> dp;
    int solve(string& s, int i, pair<int, int> p1, pair<int, int> p2) {
        if (i == n)
            return 0;

        if (dp.find({i, {p1, p2}}) != dp.end())
            return dp[{i, {p1, p2}}];

        int x = mp[s[i]].first, y = mp[s[i]].second;

        int dist1 = abs(x - p1.first) + abs(y - p1.second);
        if (p1.first == -1)
            dist1 = 0;

        int dist2 = abs(x - p2.first) + abs(y - p2.second);
        if (p2.first == -1)
            dist2 = 0;

        dist1 += solve(s, i + 1, {x, y}, p2);
        dist2 += solve(s, i + 1, p1, {x, y});

        return dp[{i, {p1, p2}}] = min(dist1, dist2);
    }
    int minimumDistance(string word) {
        n = word.size();
        char c = 'A';
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 6; j++)
                mp[c++] = {i, j};
        }
        mp['Y'] = {4, 0}, mp['Z'] = {4, 1};
        return solve(word, 0, {-1, -1}, {-1, -1});
    }
};