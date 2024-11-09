class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int>topFrequency(7,0);
        vector<int>bottomFrequency(7,0);
        vector<int>equal(7,0);

        int n = tops.size();
        int topMax = 0, bottomMax = 0;
        int top = 0, bottom = 0;
        for(int i = 0; i < n; i++){
            if(tops[i] != bottoms[i]){
                topFrequency[tops[i]]++;
                bottomFrequency[bottoms[i]]++;
            }
            if(tops[i] == bottoms[i]){
                equal[tops[i]]++;
            }
        }
        for(int i = 1; i < 7; i++){
            if(topFrequency[i]+bottomFrequency[i]+equal[i] == n){
                return abs(n-equal[i] - max(topFrequency[i],bottomFrequency[i]));
            }
        }
      
        return -1;
    }
};