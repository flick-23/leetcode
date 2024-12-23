class Solution {
public:
    void dfs(string& airport, vector<string>& itinerary,
             unordered_map<string, vector<string>>& graph) {
        while (!graph[airport].empty()) {
            string next = graph[airport].back();
            graph[airport].pop_back();
            dfs(next, itinerary, graph);
        }
        itinerary.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> graph;

        for (auto& ticket : tickets) {
            graph[ticket[0]].push_back(ticket[1]);
        }

        for (auto& [_, destinations] : graph) {
            sort(destinations.rbegin(), destinations.rend());
        }

        vector<string> itinerary;
        string start = "JFK";
        dfs(start, itinerary, graph);
        reverse(itinerary.begin(), itinerary.end());

        return itinerary;
    }
};