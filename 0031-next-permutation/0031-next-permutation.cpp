class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int point = -1, i, j, n = a.size(), temp;
        vector<int> b;
        // find break point
        for (i = n - 2; i >= 0; i--) {
            if (a[i] < a[i + 1]) {
                point = i;
                break;
            }
        }
        // if break point found, find next greatest and swap
        if (point != -1) {
            for (i = n - 1; i > point; i--) {
                if (a[i] > a[point]) {
                    temp = a[i];
                    a[i] = a[point];
                    a[point] = temp;
                    break;
                }
            }
            reverse(a.begin() + point + 1, a.end());
        }
        else{
            reverse(a.begin() ,a.end());
        } 
    }
};