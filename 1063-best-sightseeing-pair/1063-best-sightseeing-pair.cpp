class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = INT_MIN;
        int bestPrev =
            values[0] + 0; // Initialize best previous spot (values[i] + i)

        for (int j = 1; j < values.size(); j++) {
            // Compute max score using the best previous value
            maxScore = max(maxScore, bestPrev + values[j] - j);

            // Update bestPrev to be the max (values[i] + i)
            bestPrev = max(bestPrev, values[j] + j);
        }

        return maxScore;
    }
};