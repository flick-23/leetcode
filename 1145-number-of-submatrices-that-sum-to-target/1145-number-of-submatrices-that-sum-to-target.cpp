class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int count = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 1; j < cols; j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        for(int colStart = 0; colStart < cols; colStart++){
            for(int colEnd = colStart; colEnd < cols; colEnd++){
                unordered_map<int,int> prefixSumCount;
                prefixSumCount[0] = 1;
                int currSum = 0;
                for(int row = 0; row < rows; row++){
                    currSum += matrix[row][colEnd] - (colStart>0 ? matrix[row][colStart-1]: 0);
                    if(prefixSumCount.find(currSum - target) != prefixSumCount.end()){
                        count += prefixSumCount[currSum-target];
                    }
                    prefixSumCount[currSum]++;
                }
            }
        }
        return count;
    }
};