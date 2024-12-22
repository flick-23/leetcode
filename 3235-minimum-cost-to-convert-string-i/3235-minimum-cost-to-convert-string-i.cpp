class Solution {
private:
    static constexpr int CHAR_COUNT = 26;
    static constexpr int INF = 1e9;

    vector<vector<int>> buildConversionGraph(vector<char>& original,
                                             vector<char>& changed,
                                             vector<int>& cost) {
        vector<vector<int>> graph(CHAR_COUNT, vector<int>(CHAR_COUNT, INF));
        for (int i = 0; i < CHAR_COUNT; i++) {
            graph[i][i] = 0;
        }
        for (int i = 0; i < cost.size(); i++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            graph[from][to] = min(graph[from][to], cost[i]);
        }
        return graph;
    }

    void optimizeConversionPaths(vector<vector<int>>& graph) {
        for (int k = 0; k < CHAR_COUNT; k++) {
            for (int i = 0; i < CHAR_COUNT; i++) {
                if (graph[i][k] < INF) {
                    for (int j = 0; j < CHAR_COUNT; j++) {
                        if (graph[k][j] < INF) {
                            graph[i][j] =
                                min(graph[i][j], graph[i][k] + graph[k][j]);
                        }
                    }
                }
            }
        }
    }

    long long computeTotalConversionCost(string& source, string& target,
                                         vector<vector<int>>& graph) {
        long long totalCost = 0;
        for (int i = 0; i < source.length(); i++) {
            int sourceChar = source[i] - 'a';
            int targetChar = target[i] - 'a';
            if (sourceChar != targetChar) {
                if (graph[sourceChar][targetChar] == INF) {
                    return -1;
                }
                totalCost += graph[sourceChar][targetChar];
            }
        }
        return totalCost;
    }

public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        auto conversionGraph = buildConversionGraph(original, changed, cost);
        optimizeConversionPaths(conversionGraph);
        return computeTotalConversionCost(source, target, conversionGraph);
    }
};