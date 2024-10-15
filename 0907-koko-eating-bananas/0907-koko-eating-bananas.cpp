class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        // Initialize the upper bound of the search range to the maximum bananas
        // in a pile
        int high = 0;
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            high = max(high, piles[i]);
        }

        while (low <= high) {
            // Middle point of the current search range
            int k = low + (high - low) / 2;
            long int hours = 0;

            // Calculate total hours needed to eat all bananas with speed k
            for (int i = 0; i < n; i++) {
                hours += ceil((double)piles[i] / k);
            }

            // If Koko can eat all bananas within h hours with speed k
            if (hours <= h) {
                high = k - 1;
            } else {
                // Otherwise, search for a larger speed
                low = k + 1;
            }
        }

        return low;
    }
};