class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = 0, rightSum = 0, i, j;
        for(i = 0; i < k; i++){
            leftSum += cardPoints[i];
        }
        int rightPointer = cardPoints.size()-1;
        int leftPointer = i-1;
        int maxSum = leftSum;
        for(i = 0; i < k; i++){
            rightSum += cardPoints[rightPointer--];
            leftSum -= cardPoints[leftPointer--];
            maxSum = max(maxSum, rightSum + leftSum);
        }
        return maxSum;
    }
};