class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int fullTank = 0, tank = 0, start = 0;
        for(int i = 0; i < n; i++){
            fullTank += gas[i] - cost[i];
            tank += gas[i] - cost[i];
            // If fuel is negative at any station, reset start position
            if(tank < 0){
                start = i+1;    // Restart from next station
                tank = 0;       // Reset current tank
            }   
        }
        // If total fuel is positive, return start index
        return fullTank >=0 ? start : -1;
       
    }
};